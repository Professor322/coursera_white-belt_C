/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:46:24 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/22 19:46:24 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int 	main() {
	vector<bool> line;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string option;
		cin >> option;
		if (option == "WORRY_COUNT") {
			cout << count(line.start(), line.end(), true) << endl;
		} else if (option == "WORRY" || option == "QUIET") {
			int person_index;
			cin >> person_index;
			line[person_index] = (option == "WORRY");
		} else if (option == "COME") {
			int person_count;
			cin >> person_count;
			line.resize(line.size() + person_count, false);
		}
	}
	return 0;
}