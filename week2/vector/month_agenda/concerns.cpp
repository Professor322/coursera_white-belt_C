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

void 	init_months_size(vector<vector<vector<string > > >& months) {
	for (int i = 0; i < 7; i++) {
		if (i % 2 == 0) {
			months[i].resize(31);
		} else if (i % 2 != 0) {
			months[i].resize(i == 1 ? 28 : 30);
		}
	}
	for (int i = 7; i < 12; i++) {
		if (i % 2 != 0) {
			months[i].resize(31);
		} else {
			months[i].resize(30);
		}
	}
}

int 	main() {
	vector<vector<vector<string> > > months(12);
	int q, current_month = 0;

	cin >> q;
	//initialize months's lengths
	init_months_size(months);
	for (int i = 0; i < q; ++i) {

		string option;
		cin >> option;
		if (option == "ADD") {
			int day_index;
			string s;

			cin >> day_index >> s;
			months[current_month][day_index - 1].push_back(s);
		} else if (option == "NEXT") {
			//switching between months is cycled to avoid seg faults
			//when current value + 1 is becoming exactly 12 we are nullifying the next_month value
			const int next_month = (current_month + 1) % 12;
			const int  next_month_size = months[next_month].size();
			const int  curr_month_size = months[current_month].size();

			months[next_month] = months[current_month];
			months[next_month].resize(next_month_size);
			//the need to copy values is only actual when next_month_size less than current_month_size
			if (next_month_size < curr_month_size) {
				//copy every action from the days which are going to be deleted in the next month to the last day of it
				for (auto j = next_month_size; j < curr_month_size; ++j) {
					months[next_month][next_month_size - 1].insert(end(months[next_month][next_month_size - 1]),
							begin(months[current_month][j]), end(months[current_month][j]));
				}
			}
			//switch to the next month
			current_month = next_month;
		} else if (option == "DUMP") {
			int day_index;

			cin >> day_index;
			cout << months[current_month][day_index - 1].size() << " ";
			for (const string& action : months[current_month][day_index - 1]) {
				cout << action << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
