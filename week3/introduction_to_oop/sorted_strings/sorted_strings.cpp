/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_strings.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 16:29:26 by vlegros           #+#    #+#             */
/*   Updated: 2019/09/27 16:29:26 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <queue>
#include <iostream>

using namespace std;

class SortedStrings {
public:
	void AddString(const string& s) {
		sorted.push_back(s);
	}
	vector<string> GetSortedStrings() {
		sort(begin(sorted), end(sorted));
		return sorted;
	}
private:
	vector<string> sorted;
};
