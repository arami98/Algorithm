#include <iostream>

using namespace std;

long P[101];

long solve(int n) {
	if (P[n] == 0) {
		P[n] = solve(n - 1) + solve(n - 5);
		return P[n];
	}
	return P[n];
}

int main(void) {
	int T;
	cin >> T;

	P[1] = 1;
	P[2] = 1;
	P[3] = 1;
	P[4] = 2;
	P[5] = 2;
	P[6] = 3;
	P[7] = 4;
	P[8] = 5;

	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		cout << solve(n) << "\n";
	}

	return 0;
}