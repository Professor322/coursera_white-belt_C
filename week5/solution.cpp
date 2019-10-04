//
// Created by professor on 04.10.19.
//

#include <string>
#include <iostream>
#include <map>
#include <set>
#include <sstream>

using namespace std;

// Реализуйте функции и методы классов и при необходимости добавьте свои

class Date {
public:
	Date(int year, int month, int day) {
		this->year = year;
		if (month > 12 || month < 1) {
			throw invalid_argument("Month value is invalid: " + to_string(month));
		}
		this->month = month;
		if (day > 31 || day < 1) {
			throw invalid_argument("Day value is invalid: " + to_string(day));
		}
		this->day = day;
	}
	int GetYear() const { return year; }
	int GetMonth() const { return month; }
	int GetDay() const {return day; }

private:
	int year;
	int month;
	int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() == rhs.GetYear()) {
		if (lhs.GetMonth() == rhs.GetMonth())  {
			return lhs.GetDay() < rhs.GetDay();
		}
		return lhs.GetMonth() < rhs.GetMonth();
	}
	return lhs.GetYear() < rhs.GetYear();
}

bool operator ==(const Date& lhs, const Date& rhs) {
	return (lhs.GetYear() == rhs.GetYear() &&
			lhs.GetMonth() == rhs.GetMonth() &&
			lhs.GetDay() == rhs.GetDay());
}

class Database {
public:
	void AddEvent(const Date& date, const string& event) {
		data[date].insert(event);
	}
	bool DeleteEvent(const Date& date, const string& event) {
		if (data.count(date)) {
			if (data[date].count(event)) {
				data[date].erase(event);
				return true;
			}
		}
		return false;
	}
	/*int  DeleteDate(const Date& date);
	void Find(const Date& date) const;
	void Print() const;*/
private:
	map<Date, set<string> > data;
};

Date	ParseDate(stringstream& ss) {
	int year, month, day;
	ss >> year;
	ss >> month;
	ss >> day;
	if (ss.peek() != '-') {

	}
	try {
		return Date(year, month, day);
	} catch (const invalid_argument& i) {
		cout << i.what() << endl;
	}
}

int main() {
	Database db;

	string command;
	string option;
	while (getline(cin, command)) {
		if (!command.empty()) {
			stringstream ss(command);
			ss >> option;
			if (option == "Add") {

			}
		}
	}

	return 0;
}