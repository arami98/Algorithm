//#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 최단경로 탐색 알고리즘
// 특정 정점에서 다른 모든 정점으로 가는 최단경로 알려줌
// 현재까지 알고있던 최단 경로를 계속 갱신

int number = 6;
int INF = 10000000; // 무한대 표시

// 전체 그래프 초기화
//int a[6][6] = {
//	{0, 2, 5, 1, INF, INF},
//	{2, 0, 3, 2, INF, INF},
//	{5, 3, 0, 3, 1, 5},
//	{1, 2, 3, 0, 1, INF},
//	{INF, INF, 1, 1, 0, 2},
//	{INF, INF, 5, INF, 2, 0},
//};

/*bool v[6];*/ // 방문 노드
/*int d[6];*/ // 최단 거리

// 가장 최소 거리 가지는 정점 반환
//int getSmallIndex() {
//	int min = INF;
//	int index = 0;
//	for (int i = 0; i < number; i++) {
//		if (d[i] < min && !v[i]) { //방문하지 않은 노드 중 현재 최소값보다 더 작은값
//			min = d[i];
//			index = i;
//		}
//	}
//	return index;
//}

// 다익스트라 수행
//void dijkstra(int start) {
//	for (int i = 0; i < number; i++) {
//		d[i] = a[start][i];
//	}
//	v[start] = true; // 방문
//	for (int i = 0; i < number - 2; i++) {
//		int current = getSmallIndex();
//		v[current] = true;
//		for (int j = 0; j < 6; j++) {
//			if (!v[j]) {
//				if (d[current] + a[current][j] < d[j]) {
//					d[j] = d[current] + a[current][j];
//				}
//			}
//		}
//	}
//}

vector<pair<int, int> > a[7]; // 간선 정보
int d[7]; // 최소 비용

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int> > pq; // 힙구조
	pq.push(make_pair(start, 0));
	// 가까운 순서대로 처리 -> 큐 사용
	while (!pq.empty()) {
		int current = pq.top().first;
		// 짧은 것 먼저오도록 음수화(-)
		int distance = -pq.top().second;
		pq.pop();
		// 최단 거리가 아닌 경우 스킵
		if (d[current] < distance) continue;
		for (int i = 0; i < a[current].size(); i++) {
			// 선택된 노드의 인접 노드
			int next = a[current][i].first;
			// 선택된 노드 거쳐서 인접 노드로 가는 비용
			int nextDistance = distance + a[current][i].second;
			// 기존의 최소 비용보다 더 저렴하다면 교체
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
}

int main(void) {
	// 연결되지 않은 경우 비용은 무한대
	for (int i = 1; i <= number; i++) {
		d[i] = INF;
	}

	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));

	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 2));

	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(6, 5));

	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));

	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));

	a[6].push_back(make_pair(3, 5));
	a[6].push_back(make_pair(5, 2));

	dijkstra(1);
	for (int i = 1; i <= number; i++) {
		printf("%d ", d[i]);
	}
	printf("\n");
}
