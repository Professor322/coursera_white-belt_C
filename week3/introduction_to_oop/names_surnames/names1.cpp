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
		if (++it != data.end()) {
			while (++it != data.end()) {
				it->second.first_name = first_name;
			}
		}
	}
	void ChangeLastName(int year, const string& last_name) {
		data[year].last_name = last_name;
		it = data.find(year);
		if (it != data.begin()) {
			data[year].first_name = (--it)->second.first_name;
		}
		if (++it != data.end()) {
			while (++it != data.end()) {
				it->second.last_name = last_name;
			}
		}
	}
	/*void PrintData() {
		for (const auto& i : data) {
			cout << i.first << " " << i.second.first_name << " " << i.second.last_name << endl;
		}
	}*/
	string GetFullName(int year) {
		it = data.begin();

		if (year < it->first) {
			return "Incognito";
		} else {
			string result;

			while (next(it) != data.end()) {
				if (it->first >= year && next(it)->first < year) {

				}
			}
		}
	}
private:
	map<int, Persons_name> data;
	map<int, Persons_name>::iterator it;
};

int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
/*	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}
*/
	person.ChangeFirstName(1970, "Appolinaria");
/*	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}
*/
	person.ChangeLastName(1968, "Volkova");
/*	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}*/
	//person.PrintData();
	return 0;
}
