#include <iostream>
#include <string>
#include <stack>

using namespace std;

int T;

string solve(string str) {
	stack<char> stk;
	for (int j = 0; j < str.length(); j++) {
		if (str[j] == '(')
			stk.push(str[j]);
		else {
			if (stk.empty()) {
				return "NO";
			}
			if (stk.top() == '(') {
				stk.pop();
			}
		}
	}

	if (stk.empty())
		return "YES";
	else
		return "NO";
}

int main(void) {
	cin >> T;

	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;
		cout << solve(s) << "\n";
	}

	return 0;
}