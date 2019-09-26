/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:11:42 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/26 16:11:42 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int 	main() {

	int n;
	cin >> n;
	vector<int> seq(n);
	for (auto& i : seq) {
		cin >> i;
	}
	sort(begin(seq), end(seq), [](int x1, int x2){return abs(x1) < abs(x2);});
	for (const auto& i : seq) {
		cout << i << " ";
	}
	return 0;
}