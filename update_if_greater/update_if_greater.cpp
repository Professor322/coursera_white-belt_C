/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_if_greater.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:43:13 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/22 17:43:13 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

void	UpdateIfGreater(int first, int& second)
{
	if (first > second) {
		second = first;
	}
}