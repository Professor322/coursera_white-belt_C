//
// Created by Virgil Legros on 28/09/2019.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

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

private:
	map<int, string, greater<int> > fn;
	map<int, string, greater<int> > ln;
};

int main() {
	Person person;
	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	cout << "=============================================\n\n";
	person.ChangeFirstName(1900, "Solnishko");
	for (int year : {1941, 1965, 1967, 1969, 1970, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	cout << "=============================================\n\n";
	person.ChangeLastName(1900, "Lesnoe");
	for (int year : {1941, 1965, 1967, 1969, 1970, 1990}) {
		cout << person.GetFullName(year) << endl;
	}
	return 0;
}