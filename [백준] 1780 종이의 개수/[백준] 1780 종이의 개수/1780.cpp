#include <iostream>
#define MAX 2200
using namespace std;

int N;
int paper[MAX][MAX];
int cnt1, cnt2, cnt3;

void solve(int x, int y, int len) {
	int color = paper[x][y];
	bool check = true;

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (color != paper[x + i][y + j]) {
				check = false;
				break;
			}
		}
		if (check == false)
			break;
	}

	if (check) {
		if (color == -1)
			cnt1++;
		else if (color == 0)
			cnt2++;
		else
			cnt3++;
	}

	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				solve(x + i * (len/3), y + j * (len/3), len / 3);
			}
		}
	}
}

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}

	solve(0, 0, N);
	cout << cnt1 << "\n" << cnt2 << "\n" << cnt3;


	return 0;
}