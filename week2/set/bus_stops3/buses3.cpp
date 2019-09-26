/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buses3.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 23:35:57 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/25 23:35:57 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

int 	main() {
	map<set<string>, int> routes;
	int	q;

	cin >> q;
	for (int i = 0; i < q; ++i) {
		set<string> route;
		int n;

		cin >> n;
		for (int j = 0; j < n; ++j) {
			string s;

			cin >> s;
			route.insert(s);
		}
		if (routes.count(route)) {
			cout << "Already exists for " << routes[route] << endl;
		} else {
			cout << "New bus " << routes.size() + 1 << endl;
			routes[route] = routes.size() + 1;
		}
	}
	return 0;
}