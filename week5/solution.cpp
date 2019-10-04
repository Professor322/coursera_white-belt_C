//
// Created by professor on 04.10.19.
//

#include <string>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <iomanip>

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

ostream& operator <<(ostream& stream, const Date& date) {
	stream << setw(4) << setfill('0') << date.GetYear() << "-"
		   << setw(2) << setfill('0') << date.GetMonth() << "-"
		   << setw(2) << setfill('0') << date.GetDay();
	return stream;
}

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
		if (!event.empty())
			dates[date].insert(event);
	}
	bool DeleteEvent(const Date& date, const string& event) {
		if (dates.count(date)) {
			if (dates[date].count(event)) {
				dates[date].erase(event);
				return true;
			}
		}
		return false;
	}
	int  DeleteDate(const Date& date) {
		int size = dates[date].size();
		dates.erase(date);
		return size;
	}
	pair<Date, set<string> > Find(const Date& date) const {
		for (const auto& d : dates) {
			if (d.first == date) {
				return d;
			}
		}
	}
	void Print() const {
		for (const auto& d : dates) {
			cout << d.first << " ";
			for (const auto& event : d.second) {
				cout << event << " ";
			}
			cout << endl;
		}
	}
private:
	map<Date, set<string> > dates;
};

void	ensure_delimeter(stringstream& ss) {
	if (ss.peek() != '-') {
		throw invalid_argument("Wrong date format:");
	}
	ss.ignore(1);
}

Date	ParseDate(stringstream& ss, const string& command) {
	int year, month, day;

	try {
		ss >> year;
		ensure_delimeter(ss);
		ss >> month;
		ensure_delimeter(ss);
		ss >> day;
	} catch(invalid_argument& i) {
		cout << i.what() << command.substr(command.find(' ')) << endl;
		exit(1);
	}
	try {
		return Date(year, month, day);
	} catch (const invalid_argument& i) {
		cout << i.what() << endl;
		exit(2);
	}
}

int main() {
	Database db;
	string command, option, event;

	while (getline(cin, command)) {
		if (!command.empty()) {
			stringstream ss(command);
			ss >> option;
			if (option == "Add") {
				Date date = ParseDate(ss, command);
				ss >> event;
				db.AddEvent(date, event);
			} else if(option == "Find") {
				Date date = ParseDate(ss, command);
				pair<Date, set<string> > events = db.Find(date);
				if (!events.second.empty()) {
					for (const auto &e : events.second) {
						cout << e << " ";
					}
					cout << endl;
				}
			} else if (option == "Del") {
				Date date = ParseDate(ss, command);
				if (!ss.eof()) {
					ss >> event;
					if(db.DeleteEvent(date, event)) {
						cout << "Deleted successfully" << endl;
					} else {
						cout << "Event not found" << endl;
						exit(3);
					}
				} else {
					cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
				}
			} else if (option == "Print") {
				db.Print();
			} else {
				cout << "Unknown command: " << option << endl;
				exit(4);
			}
		}
	}
	return 0;
}