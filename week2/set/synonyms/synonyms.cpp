/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synonyms.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 23:14:28 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/25 23:14:28 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

int 	main() {
	map<string, set<string> > synonyms;
	int	q;

	cin >> q;
	for (int i = 0; i < q; ++i) {
		string option;

		cin >> option;
		if (option == "ADD") {
			string word1, word2;

			cin >> word1 >> word2;
			synonyms[word1].insert(word2);
			synonyms[word2].insert(word1);
		} else if (option == "COUNT") {
			string word;

			cin >> word;
			cout << synonyms[word].size() << endl;
		} else if (option == "CHECK") {
			string word1, word2;

			cin >> word1 >> word2;
			if (synonyms[word1].count(word2)) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}
