/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:36:05 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/22 18:36:05 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

using namespace std;

void Reverse(vector<int>& v) {
	int temp;

	for (int i = 0; i < v.size() / 2; ++i) {
		temp = v[i];
		v[i] = v[v.size() - 1 - i];
		v[v.size() - 1 - i] = temp;
	}
}