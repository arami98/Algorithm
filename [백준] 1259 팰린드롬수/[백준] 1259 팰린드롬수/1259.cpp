#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string str;

string pld() {
	string rstr;
	for (int i = str.length() - 1; i >= 0; i--) {
		rstr += str[i];
	}
	for (int i = 0; i < str.length(); i++) {
		if (rstr[i] == str[i])
			continue;
		else
			return "no";
	}
	return "yes";
}

int main() {
	while(true) {
		cin >> str;
		if (str == "0")
			return 0;
		cout << pld() << "\n";
	}
}