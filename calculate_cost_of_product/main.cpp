/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:00:49 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/21 17:00:49 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int 	main() {

	double n, a, b, x, y;

	cin >> n >> a >> b >> x >> y;

	double discountX = 1 - x / 100;
	double discountY = 1 - y / 100;

	if (n > b) {
		cout << n * discountX;
	}
	else if (n > a) {
		cout << n * discountY;
	}
	else {
		cout << n;
	}
	return 0;
}