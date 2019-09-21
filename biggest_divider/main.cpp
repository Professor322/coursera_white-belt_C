//
// Created by professor on 22.09.19.
//

#include <iostream>

using namespace std;

int		main() {

	int a, b, d, smallest;

	cin >> a >> b;

	while (a > 0 && b > 0) {
		if (a > b) {
			a %= b;
		} else {
			b %= a;
		}
	}
	cout << b + a;
	return 0;
}