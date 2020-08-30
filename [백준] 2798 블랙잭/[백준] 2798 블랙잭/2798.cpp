#include <iostream>
#define MAX 101
using namespace std;

int N, M;
int ans;
int card[MAX];

void dfs(int v, int sum, int cnt) {
	if (sum > M)
		return;

	if (cnt == 3) {
		if (ans < sum) {
			ans = sum;
		}
		return;
	}

	if (v == N)
		return;

	dfs(v + 1, sum, cnt);
	dfs(v + 1, sum + card[v], cnt + 1);
	return;
}

int main() {
	cin >> N >> M;
	int c;
	for (int i = 0; i < N; i++) {
		cin >> c;
		card[i] = c;
	}

	dfs(0, 0, 0);
	cout << ans << endl;
	return 0;
}