#include <stdio.h>
// dynamic programming
// 하나의 문제를 단 한번만 풀도록 하는 알고리즘

int d[100]; // 이미 구한 값 기록

int dp(int x) {
	if (x == 1) return 1;
	if (x == 2) return 1;
	if (d[x] != 0) return d[x];

	return d[x] = dp(x - 1) + dp(x - 2);
}

int main(void) {
	printf("%d\n", dp(30));
}