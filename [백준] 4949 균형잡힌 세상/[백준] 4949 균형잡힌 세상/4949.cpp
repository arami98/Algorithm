#include <iostream>
#include <stack>
#include <string>

using namespace std;

string func(string s) {
	stack<char> stk;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')
			stk.push(s[i]);
		else if (s[i] == ')') {
			if (stk.empty())
				return "no";
			else {
				if (stk.top() == '(')
					stk.pop();
				else
					return "no";
			}
		}
		if (s[i] == '[')
			stk.push(s[i]);
		else if (s[i] == ']') {
			if (stk.empty())
				return "no";
			else {
				if (stk.top() == '[')
					stk.pop();
				else
					return "no";
			}
		}
	}

	if (stk.empty())
		return "yes";
	else
		return "no";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;

	while (true) {
		getline(cin, s); // 공백 포함된 문자열 받을 때
		if (s != ".")
			cout << func(s) << "\n";
		else
			break;
	}

	return 0;
}