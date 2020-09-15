#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

int visit[MAX];
bool inRange(int a) {
	return (0 <= a && a <= MAX);
}

void sumba(int a, int b) {
	queue<int> q;
	q.push(a);
	visit[a] = 1;
	int time = 0;

	while (!q.empty()) {
		int qsize = q.size();

		while (qsize--) {
			int cur = q.front();
			if (cur == b) {
				cout << time << endl;
				return;
			}

			int next = cur + 1;
			if (inRange(next)) {
				if (visit[next] == 0) {
					q.push(next);
					visit[next] = 1;
				}
			}

			next = cur - 1;
			if (inRange(next)) {
				if (visit[next] == 0) {
					q.push(next);
					visit[next] = 1;
				}
			}

			next = cur * 2;
			if (inRange(next)) {
				if (visit[next] == 0) {
					q.push(next);
					visit[next] = 1;
				}
			}

			q.pop();
		}
		time++;
	}
	cout << -1 << endl;
}

int main() {
	int N;
	int K;
	cin >> N >> K;

	sumba(N, K);
	return 0;
}