#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 25
using namespace std;

int N, danzi;
int map[MAX][MAX];
int visit[MAX][MAX];
int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
queue<pair<int, int>> q;
vector<int> v;

void bfs(int x, int y) {
	if (visit[x][y] == 1)
		return;

	pair<int, int> cur;
	danzi++;
	int cnt = 1;
	visit[x][y] = 1; // 방문 표시
	while (!q.empty()) {
		int qsize = q.size();
		while (qsize--) {
			cur = q.front();
			int cx = cur.first;
			int cy = cur.second;

			for (int i = 0; i < 4; i++) {
				int nx = cx + dc[i];
				int ny = cy + dr[i];

				if (nx >= 0 && nx <= N - 1) {
					if (ny >= 0 && ny <= N - 1) {
						if (visit[nx][ny] == 0) {
							if (map[nx][ny] == 1) {
								visit[nx][ny] = 1;
								q.push(make_pair(nx, ny));
								cnt++;
							}
						}
					}
				}
			}
			q.pop();
		}
	}
	v.push_back(cnt);
}

int main(void) {
	string s;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			int h = s[j] - '0';
			map[i][j] = h;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));
				bfs(i, j);
			}
		}
	}
	
	sort(v.begin(), v.end());
	cout << danzi << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}

	return 0;
}