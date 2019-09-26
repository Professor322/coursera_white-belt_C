/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:09:03 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/22 16:09:03 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

using namespace	std;

bool	IsPalindrom(string s)
{
	int i = 0;

	while (s[i] == s[s.size() - 1 - i] && i < s.size() / 2)
		i++;
	//if i == s.size() / 2 than two halfs of the sting are equal and the string is a palindrom
	return i == s.size() / 2;
}
