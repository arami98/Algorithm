#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<string, int> name;

int main() {
	int N, M;
	string s;
	cin >> N >> M;
	for (int i = 0; i < N + M; i++) {
		cin >> s;
		name[s]++;
	}

	int cnt = 0;
	vector<string> temp;
	for (map<string, int>::iterator i = name.begin(); i != name.end(); i++) {
		if (i->second > 1) {
			cnt++;
			temp.push_back(i->first);
		}
	}

	cout << cnt << "\n";
	for (vector<string>::iterator iter = temp.begin(); iter != temp.end(); iter++) {
		cout << *iter << "\n";
	}
	return 0;
}