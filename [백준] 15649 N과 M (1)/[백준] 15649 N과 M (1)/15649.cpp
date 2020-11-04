#include <iostream>
using namespace std;
#define MAX 9

int N, M;
int check[MAX];
int arr[MAX];

void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!check[i]) {
			arr[cnt] = i;
			check[i] = 1;
			dfs(cnt + 1);
			check[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	dfs(0);

	return 0;
	
}