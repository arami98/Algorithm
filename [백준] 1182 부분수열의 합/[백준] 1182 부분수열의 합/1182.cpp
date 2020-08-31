#include <iostream>
using namespace std;
#define MAX 21

int nums[MAX];
int N, S, ans;

void dfs(int v, int sum, int cnt) {
	if (v == N) {
		if (sum == S&&cnt != 0) {
			ans++;
		}
		return;
	}

	dfs(v + 1, sum, cnt);
	dfs(v + 1, sum + nums[v], cnt + 1);
	return;
}

int main() {
	int n;
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> n;
		nums[i] = n;
	}
	
	dfs(0, 0, 0);
	cout << ans << endl;

	return 0;
}