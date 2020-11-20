#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int N;
int h[MAX][MAX];
int cost[MAX][MAX];

int getCost() {
	for (int i = 1; i <= N; i++) {
		cost[i][1] = min(cost[i - 1][2], cost[i - 1][3]) + cost[i][1];
		cost[i][2] = min(cost[i - 1][1], cost[i - 1][3]) + cost[i][2];
		cost[i][3] = min(cost[i - 1][1], cost[i - 1][2]) + cost[i][3];
	}

	return min(min(cost[N][1], cost[N][2]), min(cost[N][2], cost[N][3]));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> h[i][j];
			cost[i][j] = h[i][j];
		}
	}


	cout << getCost() << "\n";
}