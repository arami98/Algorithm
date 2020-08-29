#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1001
using namespace std;

int N, M;
int tomato[MAX][MAX];
int box[MAX][MAX];
int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };
int raw;
queue<pair<int,int> > q;

bool outOfRange(pair<int, int> a) {
	int x = a.first;
	int y = a.second;

	if (1 <= x && x <= N) {
		if (1 <= y && y <= M)
			return false;
	}
	return true;
}

void bfs() {
	int day = 0;
	pair<int, int> cur, next;

	if (raw == 0) {
		cout << 0 << endl;
		return;
	}

	while (!q.empty()) {
		if (raw == 0)
			break;
		int qsize = q.size();
		while (qsize--) {
			cur = q.front();
			int cx = cur.first;
			int cy = cur.second;

			for (int i = 0; i < 4; i++) {
				int nx = cx + dr[i];
				int ny = cy + dc[i];
				next.first = nx;
				next.second = ny;

				if (!outOfRange(next)) {
					if (tomato[nx][ny] == 0) {
						q.push(make_pair(nx,ny));
						tomato[nx][ny] = 1;
						raw--;
					}
				}
			}
			q.pop();
		}
		day++;
	}

	if (raw == 0)
		cout << day << endl;
	else
		cout << -1 << endl;

}

int main() {
	cin >> M >> N;
	int to;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> to;
			if (to == 0) 
				raw++;
			if (to == 1)
				q.push(make_pair(i + 1, j + 1));
			tomato[i + 1][j + 1] = to;
		}
	}
	bfs();
	return 0;
}