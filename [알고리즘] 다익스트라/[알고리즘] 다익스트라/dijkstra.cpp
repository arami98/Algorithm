//#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// �ִܰ�� Ž�� �˰���
// Ư�� �������� �ٸ� ��� �������� ���� �ִܰ�� �˷���
// ������� �˰��ִ� �ִ� ��θ� ��� ����

int number = 6;
int INF = 10000000; // ���Ѵ� ǥ��

// ��ü �׷��� �ʱ�ȭ
//int a[6][6] = {
//	{0, 2, 5, 1, INF, INF},
//	{2, 0, 3, 2, INF, INF},
//	{5, 3, 0, 3, 1, 5},
//	{1, 2, 3, 0, 1, INF},
//	{INF, INF, 1, 1, 0, 2},
//	{INF, INF, 5, INF, 2, 0},
//};

/*bool v[6];*/ // �湮 ���
/*int d[6];*/ // �ִ� �Ÿ�

// ���� �ּ� �Ÿ� ������ ���� ��ȯ
//int getSmallIndex() {
//	int min = INF;
//	int index = 0;
//	for (int i = 0; i < number; i++) {
//		if (d[i] < min && !v[i]) { //�湮���� ���� ��� �� ���� �ּҰ����� �� ������
//			min = d[i];
//			index = i;
//		}
//	}
//	return index;
//}

// ���ͽ�Ʈ�� ����
//void dijkstra(int start) {
//	for (int i = 0; i < number; i++) {
//		d[i] = a[start][i];
//	}
//	v[start] = true; // �湮
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

vector<pair<int, int> > a[7]; // ���� ����
int d[7]; // �ּ� ���

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int> > pq; // ������
	pq.push(make_pair(start, 0));
	// ����� ������� ó�� -> ť ���
	while (!pq.empty()) {
		int current = pq.top().first;
		// ª�� �� ���������� ����ȭ(-)
		int distance = -pq.top().second;
		pq.pop();
		// �ִ� �Ÿ��� �ƴ� ��� ��ŵ
		if (d[current] < distance) continue;
		for (int i = 0; i < a[current].size(); i++) {
			// ���õ� ����� ���� ���
			int next = a[current][i].first;
			// ���õ� ��� ���ļ� ���� ���� ���� ���
			int nextDistance = distance + a[current][i].second;
			// ������ �ּ� ��뺸�� �� �����ϴٸ� ��ü
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
}

int main(void) {
	// ������� ���� ��� ����� ���Ѵ�
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
