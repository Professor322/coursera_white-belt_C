/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unique.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 22:44:28 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/25 22:44:28 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include <iostream>
#include <string>

using namespace std;

int 	main() {
	set<string> unique;
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;

		cin >> s;
		unique.insert(s);
	}
	cout << unique.size() << endl;
	return 0;
}