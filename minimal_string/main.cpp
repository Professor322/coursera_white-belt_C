/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:51:34 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/21 15:51:34 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

int 	main()
{
	string a, b, c;

	cin >> a >> b >> c;
	if (a < b && a < c)
		cout << a;
	else if (b < a && b < c)
		cout << b;
	else
		cout << c;
	return 0;
}