#include <stdio.h>
#include <math.h>
// 소수 (Prime Number) 판별 알고리즘
// 특정 숫자의 제곱근 까지만 약수의 여부 검증

int number = 100000;
int a[100001];

void primeNumberSieve() {
	for (int i = 2; i <= number; i++) {
		a[i] = i;
	}
	for (int i = 2; i <= number; i++) {
		if (a[i] == 0) continue; // 이미 지워진 숫자이면 무시
		for (int j = i + i; j <= number; j += i)
			a[j] = 0;
	}
	for (int i = 2; i <= number; i++) {
		if (a[i] != 0) printf("%d ", a[i]);
	}
	printf("\n");
}

bool isPrimeNumber(int x) {
	int end = (int)sqrt(x);
	for (int i = 2; i <= end; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

//bool isPrimeNumber(int x) {
//	for (int i = 2; i < x; i++) {
//		if (x % i == 0) return false;
//	}
//	return true;
//}

int main(void) {
	//printf("%d\n", isPrimeNumber(97));

	primeNumberSieve();
	return 0;
}