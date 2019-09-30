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
	string first_name = "";
	string last_name = "";
	int 	fn_last_change = 0;
	int 	ln_last_change = 0;
};

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		if (data.count(year) && !data[year].first_name.empty()) {
			return ;
		}
		data[year].first_name = first_name;
		data[year].fn_last_change = year;
		it = data.find(year);
		if (it != data.begin()) {
			data[year].last_name = (--it)->second.last_name;
			data[year].ln_last_change = it->second.ln_last_change;
		}
		while (++it != data.end()) {
			if (it->second.fn_last_change < year) {
				it->second.first_name = first_name;
				it->second.fn_last_change = year;
			}
		}
	}
	void ChangeLastName(int year, const string& last_name) {
		if (data.count(year) && !data[year].last_name.empty()) {
			return ;
		}
		data[year].last_name = last_name;
		data[year].ln_last_change = year;
		it = data.find(year);
		if (it != data.begin()) {
			data[year].first_name = (--it)->second.first_name;
			data[year].fn_last_change = it->second.fn_last_change;
		}
		while (++it != data.end()) {
			if (it->second.ln_last_change < year) {
				it->second.last_name = last_name;
				it->second.ln_last_change = year;
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
	void PrintData() {
		for (const auto& i : data) {
			cout << i.first << endl;
			cout << i.second.first_name << " " << i.second.fn_last_change << endl;
			cout << i.second.last_name << " " << i.second.ln_last_change << endl;
			cout << endl;
		}
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

int main()
{
	Person person;

	person.ChangeLastName(1965, "Last");
	person.ChangeFirstName(1964, "First_1964_1");
	person.ChangeFirstName(1967, "First_1967");
	person.ChangeFirstName(1964, "First_1964_2");

	cout << person.GetFullName(1963) << endl;
	cout << person.GetFullName(1964) << endl;
	cout << person.GetFullName(1965) << endl;
	cout << person.GetFullName(1967) << endl;


	return 0;
}