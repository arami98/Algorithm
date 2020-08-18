#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int visitB[101];
vector<int> j[101];

void solve(int a, int b) {
	queue < pair<int, int>> q;
	
	q.push(make_pair(a, 0));
	visitB[a] = 1;

	while (!q.empty()) {
		int vertex = q.front().first;
		int chon = q.front().second;

		if (q.front().first == b) {
			cout << chon << endl;
			return;
		}

		for (int i = 0; i < j[vertex].size(); i++) {
			if (visitB[j[vertex][i]])
				continue;

			q.push(make_pair(j[vertex][i],chon + 1));
			visitB[j[vertex][i]] = 1;
		}
		q.pop();
	}

	cout << -1 << endl;
}

int main() {
	int family;
	int a;
	int b;
	int edge;
	cin >> family >> a >> b >> edge;

	int t1, t2;
	for (int i = 0; i < edge; i++) {
		cin >> t1 >> t2;
		j[t1].push_back(t2);
		j[t2].push_back(t1);
	}
	solve(a, b);

	return 0;
}