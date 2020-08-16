#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int const VNUM = 1001;
vector <int> G[VNUM];
int visit[VNUM];		//{0,-0,...}

void init() {
	for (int i = 0; i < VNUM; i++) {
		visit[i] = 0;
	}
}

void dfs(int v) {
	visit[v] = 1;
	cout << v << " ";
	//G[v]
	int vsize = G[v].size();
	for (int i = 0; i < vsize; i++) {
		int nxtv = G[v][i]; // G[v].at(i)
		if (visit[nxtv])// == 1
			continue;
		dfs(nxtv);
	}
}

void bfs(int start) {
	queue<int> q;

	//
	q.push(start);
	visit[start] = 1;

	//
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		int vsize = G[cur].size();
		for (int i = 0; i < vsize; i++) {
			int nxt = G[cur][i]; // 
			if (visit[nxt])
				continue;
			q.push(nxt);
			visit[nxt] = 1;
		}
	}
	cout << endl;
}

int main() {
	int N;
	int M;
	int V;
	int a;
	int b;

	cin >> N >> M >> V;
	
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	for (int i = 0; i < N; i++) {
		sort(G[i+1].begin(), G[i+1].end());
	}

	dfs(V);
	cout << endl;
	init();
	bfs(V);

	return 0;
}