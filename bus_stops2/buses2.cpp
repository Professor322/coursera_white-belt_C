/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buses2.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 21:48:24 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/25 21:48:24 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int 	main() {
	map<vector<string>, int> buses;
	int q;

	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n;

		cin >> n;
		vector<string> bus_stops(n);
		for (auto& bus_stop : bus_stops) {
			cin >> bus_stop;
		}
		if (!buses.count(bus_stops)) {
			int index = buses.size() + 1;
			buses[bus_stops] = index;
			cout << "New bus " << index << endl;
		} else {
			cout << "Already exists for " << buses[bus_stops] << endl;
		}
	}
	return 0;
}