#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
#define MAX 21

int R, C;
int cnt = 0;
char bord[MAX][MAX];
int visit[MAX][MAX];
int alphabet[26];
int dr[] = { -1,0,1,0 };
int dc[] = { 0,-1,0,1 };

bool inRange(pair<int, int> next, int m, int n) {
	int i = next.first;
	int j = next.second;
	if (0 < i && i <= m)
		if (0 < j && j <= n)
			return true;
	return false;
}

void dfs(pair<int,int> pos, int distance) {
	
	if (cnt < distance)
		cnt = distance;

	pair<int, int> next;
	int alpa = bord[pos.first][pos.second] - 'A';
	alphabet[alpa] = 1;
	visit[pos.first][pos.second] = 1;

	for (int i = 0; i < 4; i++) {
		next.first = pos.first + dr[i];
		next.second = pos.second + dc[i];
		alpa = bord[next.first][next.second] - 'A';

		if (!inRange(next, R, C))
			continue;
		if (visit[next.first][next.second])
			continue;
		if (alphabet[alpa])
			continue;

		dfs(next, distance + 1);
		alphabet[alpa] = 0;
		visit[next.first][next.second] = 0;
	}
}

int main() {
	string temp;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> temp;
		for (int j = 0; j < C; j++) {
			bord[i+1][j+1] = temp[j];
		}
	}

	pair<int, int> start = make_pair(1, 1);
	dfs(start, 1);
	cout << cnt << endl;

	return 0;
}