//
// Created by Virgil Legros on 29/09/2019.
//

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class ReversibleString {
public:
	ReversibleString() {}
	ReversibleString(const string& str) {
		this->s = str;
	}
	void Reverse() {
		reverse(begin(s), end(s));
	}
	string ToString() const {
		return s;
	}
private:
	string s;
};

int main() {
	ReversibleString s("live");
	s.Reverse();
	cout << s.ToString() << endl;

	s.Reverse();
	const ReversibleString& s_ref = s;
	string tmp = s_ref.ToString();
	cout << tmp << endl;

	ReversibleString empty;
	cout << '"' << empty.ToString() << '"' << endl;

	return 0;
}

