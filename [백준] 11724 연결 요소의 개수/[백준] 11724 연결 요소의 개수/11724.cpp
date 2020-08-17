#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int const VNUM = 1001;
vector <int> G[VNUM];
int visit[VNUM];		//{0,-0,...}

void init() {
	for (int i = 0; i < VNUM; i++) {
		visit[i] = 0;
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		//cout << cur << " : visited\n";
		int vsize = G[cur].size();
		for (int i = 0; i < vsize; i++) {
			int nxt = G[cur][i]; 
			if (visit[nxt])
				continue;
			q.push(nxt);
			visit[nxt] = 1;
		}
	}
}

int cntCon(int N) {
	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (visit[i] != 1) {
			bfs(i);
			count++;
		}
	}
	return count;
}

int main() {
	int N;
	int M;
	int a;
	int b;

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	cout << cntCon(N) << endl;
	return 0;
}