//
// Created by Virgil Legros on 28/09/2019.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
struct Persons{
	string name = "";
	string surname = "";
};
class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		m[year].name = first_name;
		for (auto& x: m)
			if (x.first > year)
				x.second.name = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		m[year].surname = last_name;
		for (auto& x: m)
			if (x.first > year)
				x.second.surname = last_name;
	}
	void Update(int year)
	{
		string n, s;
		for (auto& x: m)
		{
			if (x.first > year)
				break;
			if (x.second.name != "")
				n = x.second.name;
			if (x.second.surname != "")
				s = x.second.surname;
		}
		m[year].name = n;
		m[year].surname = s;
	}
	string GetFullName(int year)
	{
		//PrintMap(m);
		Update(year);
		if (m[year].name.size() != 0 && m[year].surname.size()!= 0)
			return m[year].name +" "+ m[year].surname;
		else if (m[year].name.size() == 0 && m[year].surname.size()!= 0)
			return m[year].surname + " with unknown first name";
		else if (m[year].name.size() != 0 && m[year].surname.size() == 0)
			return m[year].name + " with unknown last name";
		else if  (m[year].name.size() == 0 && m[year].surname.size() == 0)
			return "Incognito";
	}
	void PrintMap(const map<int, Persons>& m)
	{
		for (auto x: m)
			cout<<"Print: "<<x.first<<" "<<x.second.name<<" "<<x.second.surname<<endl;
		cout<<"end of map"<<endl;
	}
private:
	map<int,Persons> m;
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

	person.ChangeLastName(1960, "Pupsikova");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}
	//person.PrintMap();
	return 0;
}