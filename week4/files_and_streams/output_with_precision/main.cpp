//
// Created by Virgil Legros on 30/09/2019.
//

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int 	main() {
	fstream input("input.txt");

	if (input.is_open()) {
		cout << fixed;
		cout << setprecision(3);
		double value;
		while (input >> value) {
			cout << value << endl;
		}
	}
	return 0;
}