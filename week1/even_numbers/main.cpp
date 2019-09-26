/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:29:14 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/21 17:29:14 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int 	main() {

	int a, b;

	cin >> a >> b;
	//if the number a is even we can increment iterator by two
	if (a % 2 != 0)
		a++;
	for (int i = a; i <= b; i += 2)
			cout << i << " ";
	return 0;
}