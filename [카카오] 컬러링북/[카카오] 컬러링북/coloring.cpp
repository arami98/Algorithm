#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100
using namespace std;

int visit[MAX][MAX];
int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };
int max_size_of_one_area;

bool inRange(pair<int, int> p,int m,int n) {
	int a = p.first;
	int b = p.second;

	if (0 <= a && a < m) {
		if (0 <= b && b < n)
			return true;
	}
	return false;
}

void bfs(int x, int y, vector<vector<int>> picture, int m, int n) {
	queue<pair<int, int>> q;
	int number = 0;
	int color = picture[x][y];

	q.push(make_pair(x, y));
	visit[x][y] = 1;
	number++;

	while (!q.empty()) {
		pair<int, int> next, cur;
		cur = q.front();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dr[i];
			int ny = cur.second + dc[i];
			next = make_pair(nx, ny);

			// 범위체크
			if (!inRange(next, m, n))
				continue;
			// 방문여부
			if (visit[nx][ny])
				continue;
			// 색같은지
			if (picture[nx][ny] != color)
				continue;
			q.push(make_pair(nx, ny));
			visit[nx][ny] = 1;
			number++;
		}
		q.pop();
	}
	//가장 큰 영역
	if (max_size_of_one_area < number)
		max_size_of_one_area = number;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	max_size_of_one_area = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (picture[i][j] == 0)
				continue;
			if (visit[i][j])
				continue;
			bfs(i, j, picture,m,n);
			number_of_area++;
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}