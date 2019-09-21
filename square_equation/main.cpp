/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:59:49 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/21 15:59:49 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

using	namespace std;

int 	main(){
	double a, b, c;

	cin >> a >> b >> c;
	double d = b * b - 4 * a * c;
	//if a is equal to zero - it is linear equation
	if (a == 0) {
		if (b != 0)
			cout << -c / b;
		// if b is zero there are no roots
	}
	// if d is equal to zero there is one root
	else if (d == 0) {
		cout << -b / (2 * a);
	}
	// if d is greater than zero there are two roots
	else if (d > 0) {
		double root1 = (-b + sqrt(d)) / (2 * a);
		double root2 = (-b - sqrt(d)) / (2 * a);

		cout << root1 << " " << root2;
	}
	return 0;
}