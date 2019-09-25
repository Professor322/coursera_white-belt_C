/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countries.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:15:15 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/25 18:15:15 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <map>
#include <iostream>

using namespace std;

int 	main() {
	int n;
	map<string, string> countries;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string option;

		cin >> option;
		if (option == "CHANGE_CAPITAL") {
			string country, new_capital;

			cin >> country >> new_capital;
			if (countries.count(country)) {
				if (countries[country] == new_capital) {
					cout << "Country "<< country <<" hasn't changed its capital" << endl;
					continue ;
				} else {
					cout << "Country " << country <<" has changed its capital from "<< countries[country] << " to " << new_capital << endl;
				}
			} else  {
				cout << "Introduce new country "<< country << " with capital "<< new_capital << endl;
			}
			countries[country] = new_capital;
		} else if (option == "RENAME") {
			string old_country_name, new_country_name;

			cin >> old_country_name >> new_country_name;
			if (!countries.count(old_country_name) || old_country_name == new_country_name || countries.count(new_country_name)) {
				cout << "Incorrect rename, skip" << endl;
			} else {
				cout << "Country " << old_country_name << " with capital " << countries[old_country_name] << " has been renamed to " << new_country_name << endl;
				countries[new_country_name] = countries[old_country_name];
				countries.erase(old_country_name);
			}
		} else if (option == "ABOUT") {
			string country;

			cin >> country;
			if (!countries.count(country)) {
				cout << "Country " << country << " doesn't exist" << endl;
			} else {
				cout << "Country " << country << " has capital " << countries[country] << endl;
			}
		} else if (option == "DUMP") {
			if (countries.empty()) {
				cout << "There are no countries in the world" << endl;
			} else {
				for (const auto &country : countries) {
					cout << country.first << "/" << country.second << " ";
				}
				cout << endl;
			}
		}
	}
	return 0;
}