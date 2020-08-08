#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int const VNUM = 5;
vector <int> G[VNUM];
int visit[VNUM];		//{0,-0,...}

void init() {
	for (int i= 0; i < VNUM; i++) {
		visit[i] = 0;
	}
}

void dfs(int v) {
	visit[v] = 1;
	cout << v << " : visit" << endl;
	//G[v] 내 자식들 담겨있음
	int vsize = G[v].size();
	for (int i = 0; i < vsize; i++) {
		int nxtv = G[v][i]; // G[v].at(i)
		if (visit[nxtv] )// == 1
			continue;
		dfs(nxtv);
	}
}

void bfs(int start) {
	queue<int> q;

	//첫 시작
	q.push(start);
	visit[start] = 1;

	//본격 시작
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " : visited\n";
		int vsize = G[cur].size();
		for (int i = 0; i < vsize; i++) {
			int nxt = G[cur][i]; // 자식
			if (visit[nxt])
				continue;
			q.push(nxt);
			visit[nxt] = 1;
		}
	
	}
}

int main() {
	//vertex 0
	G[0].push_back(1);
	G[0].push_back(2);
	G[0].push_back(4);

	//vertex 1
	G[1].push_back(0);
	G[1].push_back(2);

	//vertex2
	G[2].push_back(0);
	G[2].push_back(1);
	G[2].push_back(3);
	G[2].push_back(4);

	//vertex3
	G[3].push_back(2);
	G[3].push_back(4);

	//vertex4
	G[4].push_back(0);
	G[4].push_back(2);
	G[4].push_back(3);
	
	bfs(3);
}