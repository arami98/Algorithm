#include <iostream>
#define MAX 500
using namespace std;

int N, M, B;
int ground[MAX][MAX];
int calcMin = 999999999;
int height;

void calc(int min, int max) {
	int calcTime;
	for (int h = min; h <= max; h++) {
		int build = 0;
		int remove = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (ground[i][j] < h)
					build += (h - ground[i][j]);
				if (ground[i][j] > h)
					remove += (ground[i][j] - h);
			}
		}

		if ((remove + B) < build)
			continue;
		else {
			calcTime = remove * 2 + build;
			if (calcTime <= calcMin) {
				calcMin = calcTime;
				height = h;
			}
		}
	}
}

int main(void) {
	cin >> N >> M >> B;
	int max = 0;
	int min = 999999999;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ground[i][j];
			if (ground[i][j] > max)
				max = ground[i][j];
			if (ground[i][j] < min)
				min = ground[i][j];
		}
	}

	calc(min, max);
	cout << calcMin << " " << height;

	return 0;
}