/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_strings.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:56:30 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/22 17:56:30 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

void	MoveStrings(vector<string>& source, vector<string>& destination)
{
	for (auto s : source) {
		destination.push_back(s);
	}
	source.clear();
}