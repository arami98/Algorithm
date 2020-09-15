#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 101
using namespace std;

int map[MAX][MAX];
int visit[MAX][MAX];
int N, M;

int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };

bool outOfRange(pair<int, int> a) {
	int x = a.first;
	int y = a.second;

	if (1 <= x && x <= N) {
		if (1 <= y && y <= M)
			return false;
	}
	return true;
}

void solve() {
	queue<pair<int, int> > q;

	pair <int, int> cur, next;
	int len = 1;

	q.push(make_pair(1, 1));
	visit[1][1] = 1;

	while(!q.empty()){
		int qsize = q.size();

		while (qsize--) {
			cur = q.front();
			int cx = cur.first;
			int cy = cur.second;

			if (cx == N && cy == M) {
				cout << len << endl;
				return;
			}

			for (int i = 0; i < 4; i++) {
				int nx = cx + dr[i];
				int ny = cy + dc[i];
				next.first = nx;
				next.second = ny;

				if (visit[nx][ny] == 0) {
					if (map[nx][ny] == 1) {
						if (!outOfRange(next)) {
							q.push(make_pair(nx, ny));
							visit[nx][ny] = 1;
						}
					}
				}
			}
			q.pop();
		}
		len++;
	}

	cout << -1 << endl;
}

int main() {
	cin >> N >> M;
	string temp;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		for (int j = 0; j < M; j++) {
			map[i + 1][j + 1] = temp[j] - '0';
		}
	}

	solve();

	return 0;
}