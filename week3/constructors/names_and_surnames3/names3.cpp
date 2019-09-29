//
// Created by Virgil Legros on 29/09/2019.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

string	GetNamesHistory(map<int, string>::const_iterator it_ln, map<int, string>::const_iterator end) {
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
	Person(const string& first_name, const string& last_name, int birth_year) {
		this->birth_year = birth_year;
		fn[birth_year] = first_name;
		ln[birth_year] = last_name;
	}
	void ChangeFirstName(int year, const string& first_name) {
		if (year >= birth_year)
			fn[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		if (year >= birth_year)
			ln[year] = last_name;
	}
	string GetFullName(int year) const {
		auto it_fn = fn.lower_bound(year), it_ln = ln.lower_bound(year);
		if (it_fn == fn.end() && it_ln == ln.end()) {
			return "No person";
		} else if (it_fn == fn.end()) {
			return it_ln->second + " with unknown first name";
		} else if (it_ln == ln.end()){
			return it_fn->second + " with unknown last name";
		} else {
			return it_fn->second + " " + it_ln->second;
		}
	}

	string GetFullNameWithHistory(int year) const {
		auto it_fn = fn.lower_bound(year), it_ln = ln.lower_bound(year);
		string result;
		if (it_fn == fn.end() && it_ln == ln.end()) {
			return "No person";
		} else if (it_fn == fn.end()) {
			return GetNamesHistory(it_ln, ln.end()) + " with unknown first name";
		} else if (it_ln == ln.end()){
			return GetNamesHistory(it_fn, fn.end()) + " with unknown last name";
		} else {
			return GetNamesHistory(it_fn, fn.end()) + " " + GetNamesHistory(it_ln, ln.end());
		}
	}
private:
	int birth_year;
	map<int, string, greater<int> > fn;
	map<int, string, greater<int> > ln;
};

