//
// Created by professor on 04.10.19.
//

#include <string>
#include <system_error>
#include <iostream>

using namespace std;

string AskTimeServer() {

}

class TimeServer {
public:
	string GetCurrentTime() {
		try {
			LastFetchedTime = AskTimeServer();
		} catch (const system_error& e) {

		}
		return LastFetchedTime;
	}
private:
	string LastFetchedTime = "00:00:00";
};
