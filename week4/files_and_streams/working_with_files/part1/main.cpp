//
// Created by Virgil Legros on 30/09/2019.
//

#include <iostream>
#include <fstream>

using namespace std;

int 	main() {
	ifstream input("input.txt");

	if (input.is_open()) {
		string line;
		while (getline(input, line)) {
			cout << line << endl;
		}
	}
 	return 0;
}