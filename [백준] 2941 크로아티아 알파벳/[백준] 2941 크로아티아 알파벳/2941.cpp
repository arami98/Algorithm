#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(void) {
	int cnt = 0;
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'l') {
			if (s[i + 1] == 'j') {
				cnt++;
				i++;
				continue;
			}
		}
		else if (s[i] == 'n') {
			if (s[i + 1] == 'j') {
				cnt++;
				i++;
				continue;
			}
		}
		else if (s[i] == 's') {
			if (s[i + 1] == '=') {
				cnt++;
				i++;
				continue;
			}
		}
		else if (s[i] == 'z') {
			if (s[i + 1] == '=') {
				cnt++;
				i++;
				continue;
			}
		}
		else if (s[i] == 'c') {
			if (s[i + 1] == '=') {
				cnt++;
				i++;
				continue;
			}
			else if (s[i + 1] == '-') {
				cnt++;
				i++;
				continue;
			}
		}
		else if (s[i] == 'd') {
			if (s[i + 1] == '-') {
				cnt++;
				i++;
				continue;
			}
			else if (s[i + 1] == 'z') {
				if (s[i + 2] == '=') {
					cnt++;
					i += 2;
					continue;
				}
			}
		}
		cnt++;
	}

	cout << cnt;
	return 0;
}