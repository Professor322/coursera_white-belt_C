/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buses1.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:35:25 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/25 20:35:25 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int 	main() {
	map<string, vector<string> > buses, stops;
	int q;
	string bus, option;

	cin >> q;
	for (int i = 0; i < q; ++i) {
		cin >> option;
		if (option == "NEW_BUS") {
			int stop_count;
			string stop_name;

			cin >> bus >> stop_count;
			vector<string>& stops_vec = buses[bus];
			stops_vec.resize(stop_count);
			for (auto &stop: stops_vec) {
				cin >> stop;
				stops[stop].push_back(bus);
			}
		} else if (option == "BUSES_FOR_STOP") {
			string stop_name;

			cin >> stop_name;
			if (stops.count(stop_name)) {
				for (const auto& bus_num : stops[stop_name]) {
					cout << bus_num << " ";
				}
			} else {
				cout << "No stop";
			}
			cout << endl;
		} else if (option == "STOPS_FOR_BUS") {
			cin >> bus;
			if (buses.count(bus)) {
				for (const auto& stop_name : buses[bus]) {
					cout << "Stop " << stop_name << ": ";
					if (stops.count(stop_name)) {
						if (stops[stop_name].size() == 1 && stops[stop_name][0] == bus) {
							cout << "no interchange";
						} else {
							for (const auto &bus_num : stops[stop_name]) {
								if (bus_num != bus)
									cout << bus_num << " ";
							}
						}
						cout << endl;
					}
				}
			} else {
				cout << "No bus" << endl;
			}
		} else if (option == "ALL_BUSES") {
			if (!buses.empty()) {
				for (const auto& bus_num : buses) {
					cout << "Bus " << bus_num.first << ": ";
					for (const auto& stop_name: bus_num.second) {
						cout << stop_name << " ";
					}
					cout << endl;
				}
			} else {
				cout << "No buses" << endl;
			}
		}
	}
	return 0;
}