/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_values.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 22:49:49 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/25 22:49:49 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <string>
#include <set>
#include <iostream>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
	set<string> result;

	for (const auto& elem : m) {
		result.insert(elem.second);
	}
	return (result);
}
