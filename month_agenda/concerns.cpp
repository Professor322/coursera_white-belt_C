/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concerns.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:33:20 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/22 21:33:20 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int 	main() {
	vector<vector<vector<string> > > months(12);
	int q, current_month = 0;

	cin >> q;
	for (int i = 0; i < 12; ++i) {
		if (i % 2 == 0) {
			months[i].resize(31);
		} else if (i == 1) {
			months[i].resize(28);
		} else {
			months[i].resize(30);
		}
	}
	for (int i = 0; i < q; ++i) {
		string option;
		cin >> option;
		if (option == "ADD") {
			int index;
			string s;

			cin >> index >> s;
			months[current_month][index - 1].push_back(s);
		} else if (option == "NEXT") {
			const int next_month = current_month + 1 == 12 ? 0 : current_month + 1;
			if (current_month % 2 == 0) {
				const int num_of_days = months[next_month].size();

				months[next_month] = months[current_month];
				months[next_month].resize(num_of_days);
				for (auto j = num_of_days; j < 31; ++j) {
					months[next_month][num_of_days - 1].insert(end(months[next_month][num_of_days - 1]), begin(months[current_month][j]), end(months[current_month][j]));
				}
			} else if (current_month % 2 != 0) {
				months[next_month] = months[current_month];
				months[next_month].resize(31);
			}
			current_month = next_month;
		} else if (option == "DUMP") {
			int index;

			cin >> index;
			cout << months[current_month][index - 1].size() << " ";
			for (auto action : months[current_month][index - 1]) {
				cout << action << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
