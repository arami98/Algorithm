#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K, N;
vector<long> ran;

long cut(long c) {
	long res = 0;
	for (int i = 0; i < K; i++) {
		if(ran[i] >= c)
			res += (ran[i] / c);
	}
	return res;
}

long b_search(long start, long end) {
	long mid = (start + end) / 2;

	if (start > end)
		return end;
	
	if (cut(mid) < N)
		return b_search(start, mid - 1);

	else
		return b_search(mid + 1, end);
	
}

int main() {
	cin >> K >> N;
	long temp;

	for (int i = 0; i < K; i++) {
		cin >> temp;
		ran.push_back(temp);
	}

	sort(ran.begin(), ran.end());
	cout << b_search(1, ran.back());
}