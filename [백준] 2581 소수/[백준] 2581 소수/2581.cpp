#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int prime[10000];
vector<int> v;

void findPrime(int n) {
	prime[0] = 1;

	for (int i = 2; i <= sqrt(n); i++) {
		for (int j = 2; j * i <= n; j++) {
			prime[i*j - 1] = 1;
		}
	}
}

int main() {
	int M;
	int N;
	int sum = 0;
	cin >> M >> N;

	findPrime(N);

	for (int i = M - 1; i < N; i++) {
		if (prime[i] == 0) {   //소수이면
			sum += i + 1;
			v.push_back(i + 1);
		}
	}

	if (sum == 0)
		cout << "-1" << endl;
	else
		cout << sum << " " << v.at(0)<< endl; 

	return 0;
}