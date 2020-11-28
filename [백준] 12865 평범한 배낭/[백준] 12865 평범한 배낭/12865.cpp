#include <iostream>
#include <algorithm>
#define WEG 100001
#define VAL 101
using namespace std;

int N, K;
int w[VAL];
int v[VAL];
int bag[VAL][WEG];

int dp() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (w[i] > j)
				bag[i][j] = bag[i - 1][j];
			else
				bag[i][j] = max(bag[i - 1][j - w[i]] + v[i], bag[i - 1][j]);
		}
	}
	return bag[N][K];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	
	for (int i = 0; i < N; i++) {
		cin >> w[i + 1] >> v[i + 1];
	}
	cout << dp() << "\n";
}