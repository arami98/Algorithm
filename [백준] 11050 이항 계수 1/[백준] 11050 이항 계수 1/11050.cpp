#include <iostream>
using namespace std;

int N, K;

int fac(int i) {
	if (i == 1)
		return 1;
	return i * fac(i - 1);
}

int main() {
	cin >> N >> K;
	//int ans = 1;
	//int div = 1;
	//int k = K;
	//for (int i = 0; i < K; i++) {
	//	ans *= N;
	//	div *= k;
	//	N--;
	//	k--;
	//}
	cout << fac(N) / (fac(K) * fac(N-K));

	return 0;
}