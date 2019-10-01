//
// Created by Virgil Legros on 30/09/2019.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Date {
	int day;
	int month;
	int year;
};

struct Student{
	string first_name;
	string last_name;
	Date date;
};

int 	main() {

	int n;
	cin >> n;
	vector<Student> students(n);
	for (auto& student : students) {
		cin >> student.first_name;
		cin >> student.last_name;
		cin >> student.date.day;
		cin >> student.date.month;
		cin >> student.date.year;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		string option;
		int 	k;

		cin >> option;
		cin >> k;
		if ((option != "name" && option != "date") || k < 1 || k > n) {
			cout << "bad request" << endl;
		} else if (option == "name") {
			cout << students[k - 1].first_name << " " << students[k - 1].last_name << endl;
		} else if (option == "date") {
			cout << students[k - 1].date.day << "." << students[k - 1].date.month << "."
			<< students[k - 1].date.year << endl;
		}
	}
	return 0;
}