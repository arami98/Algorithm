#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int prime[1000000];

void findPrime(int n) {

	for (int i = 2; i <= sqrt(n); i++) {
		for (int j = 2; j * i <= n; j++) {
			prime[i*j - 1] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M;
	int N;
	cin >> M >> N;
	prime[0] = 1;

	findPrime(N);

	for (int i = M-1; i < N; i++) {
		if (prime[i] == 0)
			cout << i + 1 << "\n";
	}
	return 0;
}