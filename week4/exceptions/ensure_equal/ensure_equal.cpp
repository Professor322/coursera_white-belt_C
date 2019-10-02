//
// Created by professor on 02.10.19.
//

#include <string>
#include <iostream>

using namespace std;

void EnsureEqual(const string& left, const string& right) {
	if (left != right) {
		throw runtime_error(left + " != " + right);
	}
}
