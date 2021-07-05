#include <iostream>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, n, m;
	map<int, int> num;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> n;
		num.insert(make_pair(n, 1));
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> m;
		if(num[m] == 1)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";

	}


	return 0;
}