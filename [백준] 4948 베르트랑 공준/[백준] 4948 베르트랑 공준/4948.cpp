#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int prime[123456 * 2];

void findPrime(int n) {
	prime[0] = 1;

	for (int i = 2; i <= sqrt(n); i++) {
		for (int j = 2; j *i <= n; j++) {
			prime[i * j - 1] = 1;
		}
	}
}

int main() {
	int n;
	while (1) {
		cin >> n;
		int count = 0;
		if (n == 0)
			break;
		findPrime(2 * n);
		for (int i = n; i < 2 * n; i++) {
			if (prime[i] == 0)
				count++;
		}
		cout << count << endl;
	}
	return 0;
}