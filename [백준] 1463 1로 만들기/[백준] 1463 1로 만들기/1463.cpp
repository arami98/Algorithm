#include <iostream>
#include <queue>
using namespace std;

int visit[1000001];

void calc(int n) {
	queue<int> q;
	q.push(n);
	visit[n] = 1;
	int cnt = 0;

	while (!q.empty()) {
		int qsize = q.size();

		while (qsize--) {
			int cur = q.front();
			if (cur == 1) {
				cout << cnt << endl;
				return;
			}

			if (cur % 3 == 0) {
				int next = cur / 3;
				if (visit[next] == 0) {
					q.push(next);
					visit[next] = 1;
				}
			}

			if (cur % 2 == 0) {
				int next = cur / 2;
				if (visit[next] == 0) {
					q.push(next);
					visit[next] = 1;
				}
			}

			
			int next = cur - 1;
			if (visit[next] == 0) {
				q.push(next);
				visit[next] = 1;
			}

			q.pop();
		}
		cnt++;
	}
	cout << -1 << endl;
}

int main() {
	int N;
	cin >> N;
	calc(N);
}