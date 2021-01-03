#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long> tree;
int N, M;

long cut(long c) {
	long res = 0;
	for (int i = 0; i < N; i++) {
		if (tree[i] > c)
			res += (tree[i] - c);
	}
	return res;
}

long b_search(long start, long end) {
	long mid = (start + end) / 2;

	if (start > end) {
		return end;
	}

	if (cut(mid) < M)
		return b_search(start, mid - 1);

	else
		return b_search(mid + 1, end);
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		tree.push_back(t);
	}

	sort(tree.begin(), tree.end());
	cout << b_search(0,tree.back());
}