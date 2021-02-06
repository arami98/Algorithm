#include <iostream>
#include <map>
#include <string>
using namespace std;

int N, M;
map<string, string> pw;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> M;
	string key;
	string val;
	string find;

	for (int i = 0; i < N; i++) {
		cin >> key >> val;

		pw.insert(make_pair(key, val));
	}

	for (int i = 0; i < M; i++) {
		cin >> find;
		cout << pw[find] << "\n";
	}

	return 0;
}