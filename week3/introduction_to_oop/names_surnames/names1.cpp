/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   names1.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 16:42:56 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/27 16:42:56 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <map>
#include <iostream>

using namespace std;

struct Persons_name {
	string first_name;
	string last_name;
};

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		data[year].first_name = first_name;
		it = data.find(year);
		if (it != data.begin()) {
			data[year].last_name = (--it)->second.last_name;
		}
		if (it != data.end()) {
			while (++it != data.end()) {
				if (it->second.first_name.empty()) {
					it->second.first_name = first_name;
				}
			}
		}
	}
	void ChangeLastName(int year, const string& last_name) {
		data[year].last_name = last_name;
		it = data.find(year);
		if (it != data.begin()) {
			data[year].first_name = (--it)->second.first_name;
		}
		if (it != data.end()) {
			while (++it != data.end()) {
				if (it->second.last_name.empty()) {
					it->second.last_name = last_name;
				}
			}
		}
	}
	string GetFullName(int year) {
		it = data.begin();

		if (data.empty() || year < it->first) {
			return "Incognito";
		}
		while (next(it) != data.end()) {
			if (year >= it->first && year < next(it)->first) {
				return FormatFullName();
			}
			it++;
		}
		return FormatFullName();
	}
private:
	map<int, Persons_name> data;
	map<int, Persons_name>::iterator it;
	string	FormatFullName() {
		if (it->second.first_name.empty()) {
			return it->second.last_name + " with unknown first name";
		} else if (it->second.last_name.empty()) {
			return it->second.first_name + " with unknown last name";
		} else {
			return it->second.first_name + " " + it->second.last_name;
		}
	}
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

	person.ChangeFirstName(1965, "Polina");
	for (int year : {1964, 1965, 1966, 1967}) {
		cout << person.GetFullName(year) << endl;
	}

	return 0;
}
