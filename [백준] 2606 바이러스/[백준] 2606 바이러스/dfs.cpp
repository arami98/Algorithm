#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

int C;
int virus = 0;
vector<int> computer[MAX];
int visit[MAX];

void dfs(int v) {
	visit[v] = 1;
	int vsize = computer[v].size();

	for (int i = 0; i < vsize; i++) {
		int next = computer[v][i];
		if (visit[next])
			continue;
		virus++;
		dfs(next);
	}
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

	dfs(1);
	cout << virus << endl;
	return 0;
}