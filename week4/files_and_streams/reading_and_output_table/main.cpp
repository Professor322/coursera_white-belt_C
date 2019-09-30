//
// Created by Virgil Legros on 30/09/2019.
//

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

void 	PrintTable(const vector<vector<int> >& data) {
	for (auto i = 0; i < data.size(); ++i) {
		for (auto j = 0; j < data[i].size(); ++j) {
			cout << setw(10) << data[i][j];
			if (j != data[i].size() - 1)
				cout << " ";
		}
		if (i != data.size() - 1)
			cout << endl;
	}
}

int 	main() {
	ifstream input("input.txt");
	int n, m;
	input >> n >> m;
	vector<vector<int> > data(n);
	for (auto& row : data) {
		row.resize(m);
		for (auto& elem : row) {
			input >> elem;
			input.ignore(1);
		}
	}
	PrintTable(data);
	return 0;
}