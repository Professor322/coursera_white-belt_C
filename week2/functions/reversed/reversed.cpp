/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reversed.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:42:23 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/22 18:42:23 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v)
{
	auto seq = input;
	for (int i = 0; i < seq.size() / 2; ++i) {
		auto tmp = seq[i];
		seq[i] = seq[seq.size() - 1 - i];
		seq[seq.size() - 1 - i] = tmp;
	}
	return seq;
}