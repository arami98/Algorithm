#include <iostream>
using namespace std;

int dfs(int cur, int n, int cnt) {
	if (cur > n)
		return cnt;

	if (cur < 100)
		dfs(cur + 1, n, cnt + 1);

	else if (cur < 1000) {
		int a = cur / 100;
		int b = cur % 100 / 10;
		int c = cur % 10;
		if (a - b == b - c)
			dfs(cur + 1, n, cnt + 1);
		else
			dfs(cur + 1, n, cnt);
	}

	else
		dfs(cur + 1, n, cnt);
}

int main() {
	int N;
	int cnt = 0;
	cin >> N;

	//for (int i = 1; i <= N; i++) {
	//	if (i <= 99) {
	//		cnt++;
	//		continue;
	//	}
	//	if (i == 1000)
	//		continue;
	//	int a = i / 100;
	//	int b = i % 100 / 10;
	//	int c = i % 10;
	//	if (a - b == b - c)
	//		cnt++;
	//}
	//cout << cnt << endl;

	cout << dfs(1, N, cnt) << endl;
	return 0;
}