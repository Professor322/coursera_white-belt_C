//
// Created by Virgil Legros on 29/09/2019.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

string	GetNamesHistory(map<int, string>::iterator it_ln, map<int, string>::iterator end) {
	vector<string> history;

	history.push_back(it_ln->second);
	while (++it_ln != end) {
		if (history[history.size() - 1] == it_ln->second) {
			continue ;
		}
		history.push_back(it_ln->second);
	}
	if (history.size() == 1) {
		return history[0];
	} else {
		string result = history[0] + " (";
		for (auto it = history.begin() + 1; it != history.end(); ++it) {
			result += *it + ", ";
		}
		result[result.size() - 2] = ')';
		result.pop_back();
		return result;
	}
}

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		fn[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		ln[year] = last_name;
	}
	string GetFullName(int year) {
		auto it_fn = fn.lower_bound(year), it_ln = ln.lower_bound(year);
		if (it_fn == fn.end() && it_ln == ln.end()) {
			return "Incognito";
		} else if (it_fn == fn.end()) {
			return it_ln->second + " with unknown first name";
		} else if (it_ln == ln.end()){
			return it_fn->second + " with unknown last name";
		} else {
			return it_fn->second + " " + it_ln->second;
		}
	}
	string GetFullNameWithHistory(int year) {
		auto it_fn = fn.lower_bound(year), it_ln = ln.lower_bound(year);
		string result;
		if (it_fn == fn.end() && it_ln == ln.end()) {
			return "Incognito";
		} else if (it_fn == fn.end()) {
			return GetNamesHistory(it_ln, ln.end()) + " with unknown first name";
		} else if (it_ln == ln.end()){
			return GetNamesHistory(it_fn, fn.end()) + " with unknown last name";
		} else {
			return GetNamesHistory(it_fn, fn.end()) + " " + GetNamesHistory(it_ln, ln.end());
		}
	}
private:
	map<int, string, greater<int> > fn;
	map<int, string, greater<int> > ln;
};

int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1990, "Polina");
	person.ChangeLastName(1990, "Volkova-Sergeeva");
	cout << person.GetFullNameWithHistory(1990) << endl;

	person.ChangeFirstName(1966, "Pauline");
	cout << person.GetFullNameWithHistory(1966) << endl;

	person.ChangeLastName(1960, "Sergeeva");
	for (int year : {1960, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeLastName(1961, "Ivanova");
	cout << person.GetFullNameWithHistory(1967) << endl;

	return 0;
}
