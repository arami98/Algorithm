#include <iostream>
#define MAX 128
using namespace std;

int N;
int white = 0;
int blue = 0;
int paper[MAX][MAX];

void check(int len, int x, int y) {
	int start = paper[x][y];

	for (int i = x; i < x+len; i++) {
		for (int j = y; j < y+len; j++) {
			if (start != paper[i][j]) {
				check(len / 2, x, y);
				check(len / 2, x, y + len / 2);
				check(len / 2, x + len / 2, y);
				check(len / 2, x + len / 2, y + len / 2);
				return;
			}
		}
	}
	if (start == 1)
		blue++;
	else
		white++;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}

	check(N, 0, 0);
	cout << white << "\n" << blue << "\n";
}