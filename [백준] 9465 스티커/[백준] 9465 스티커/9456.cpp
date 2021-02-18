#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

int T, n;
int sticker[2][MAX];
int arr[2][MAX];

int dp() {
	arr[0][0] = sticker[0][0];
	arr[1][0] = sticker[1][0];
	arr[0][1] = sticker[1][0] + sticker[0][1];
	arr[1][1] = sticker[0][0] + sticker[1][1];

	for (int i = 2; i < n; i++) {
		arr[0][i] = max(max(arr[0][i - 2], arr[1][i - 2]), arr[1][i - 1]) + sticker[0][i];
		arr[1][i] = max(max(arr[0][i - 2], arr[1][i - 2]), arr[0][i - 1]) + sticker[1][i];
	}

	return max(arr[0][n - 1], arr[1][n - 1]);
}

int main(void) {
	cin >> T;
	int s;

	while (T > 0) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> s;
				sticker[i][j] = s;
			}
		}
		cout << dp() << "\n";
		T--;
	}
	return 0;
}