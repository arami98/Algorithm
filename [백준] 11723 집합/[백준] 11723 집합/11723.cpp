#include <iostream>
#include <set>
#include <string>
#define MAX 21
using namespace std;

int S[MAX];
set<int> s;

void calc(string func, int x) {
	if (func == "add") {
		S[x] = 1;
	}

	else if (func == "remove") {
		S[x] = 0;
	}

	else if (func == "check") {
		if (S[x] == 0) // Á¸Àçx
			cout << 0 << "\n";
		else
			cout << 1 << "\n";
	}

	else if (func == "toggle") {
		if (S[x] == 1) {
			S[x] = 0;
		}
		else
			S[x] = 1;
	}

}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, x;
	string func;
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> func;
		if (func == "all") {
			for (int i = 1; i <= 20; i++) {
				S[i] = 1;
			}
			continue;
		}
		if (func == "empty") {
			for (int i = 1; i <= 20; i++) {
				S[i] = 0;
			}
			continue;
		}
		cin >> x;
		calc(func, x);
	}

	return 0;
}