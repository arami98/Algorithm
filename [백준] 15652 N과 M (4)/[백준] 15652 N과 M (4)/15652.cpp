#include <iostream>
#define MAX 9
using namespace std;

int N, M;
int arr[MAX];

void dfs(int num, int cnt) {
	if (M == cnt) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = num; i <= N; i++) {
		arr[cnt] = i;
		dfs(i, cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> M;
	dfs(1,0);
}