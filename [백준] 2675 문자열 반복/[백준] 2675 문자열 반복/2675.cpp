#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int T, R;
	string S, P;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> R >> S;
		for (int i = 0; i < S.length(); i++) {
			for (int j = 0; j < R; j++) {
				P += S[i];
			}
		}
		cout << P << "\n";
		P.clear();
	}

	return 0;
}