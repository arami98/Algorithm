#include <iostream>
using namespace std;
#define MAX 9

int N, M;
int visit[MAX];
int arr[MAX];

void dfs(int cnt, int num) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = num; i <= N; i++) {
		if (!visit[i]) {
			arr[cnt] = i;
			visit[i] = 1;
			dfs(cnt + 1, i+1);
			visit[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	dfs(0,1);
	return 0;
}