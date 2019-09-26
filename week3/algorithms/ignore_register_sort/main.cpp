/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:23:05 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/26 16:23:05 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int 	main() {
	int n;
	cin >> n;
	vector<string> seq(n);

	for (auto& i : seq) {
		cin >> i;
	}
	sort(begin(seq), end(seq),
			[](const string &s1, const string &s2) {
				return lexicographical_compare(
						begin(s1), end(s1),
						begin(s2), end(s2),
						[](char c1, char c2) { return tolower(c1) < tolower(c2); }
				);
			}
	);
	for (const auto& i : seq) {
		cout << i << " ";
	}
	return 0;
}