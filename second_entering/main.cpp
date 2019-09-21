/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:38:18 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/21 17:38:18 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int 	main() {
	string s;
	int result = -2;

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'f') {
			if (result == -2) {
				result--;
			} else if (result == -1) {
				result = i;
				break ;
			}
		}
	}
	cout << result;
	/*for (int i = 0; i < s.size(); i++)
		if (s[i] == 'f') {
			counter++;
			if (counter == 2) {
				cout << i;
				break ;
			}
		}
	if (counter == 0) {
		cout << "-2";
	}
	else if (counter == 1) {
		cout << "-1";
	}*/
	return 0;
}