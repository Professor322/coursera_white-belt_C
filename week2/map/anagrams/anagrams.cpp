/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anagrams.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:42:45 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/25 17:42:45 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include <string>

using namespace std;

map<char, int>	BuildCharCounters(const string& s) {
	map<char, int> char_counter;

	for (auto c:s) {
		char_counter[c]++;
	}
	return char_counter;
}

int 	main() {
	int n;

	cin >>  n;
	for (int i = 0; i < n; ++i) {
		string s1, s2;
		cin >> s1 >> s2;
		if (BuildCharCounters(s1) == BuildCharCounters(s2)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}