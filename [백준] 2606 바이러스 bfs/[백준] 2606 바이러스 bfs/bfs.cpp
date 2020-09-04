#include <iostream>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;

int C;
vector<int> computer[MAX];
int visit[MAX];

int bfs(int v) {
	queue<int> q;
	int virus = 0;
	q.push(v);
	visit[v] = 1;

	while (!q.empty()) {
		int cur = q.front();
		int vsize = computer[cur].size();

		for (int i = 0; i < vsize; i++) {
			int next = computer[cur][i];
			if (visit[next] == 0) {
				visit[next] = 1;
				virus++;
				q.push(next);
			}
		}
		q.pop();
	}
	return virus;
}

int main() {
	int con;
	int n1, n2;
	cin >> C >> con;

	for (int i = 0; i < con; i++) {
		cin >> n1 >> n2;
		computer[n1].push_back(n2);
		computer[n2].push_back(n1);
	}

	cout << bfs(1) << endl;
	return 0;
}