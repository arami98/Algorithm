#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Nan;
vector<int> real;

void dfs(int v, int sum, int cnt) {
	if (v == 9) {
		if (sum == 100 && cnt == 7) {
			//난쟁이출력
			for (int i = 0; i < 7; i++) {
				cout << real[i] << endl;
			}
			exit(0);
		}
		return;
	}

	real.push_back(Nan[v]);
	dfs(v + 1, sum + Nan[v], cnt + 1);

	real.pop_back();
	dfs(v + 1, sum, cnt);
	return;
}

int main() {
	int h;

	for (int i = 0; i < 9; i++) {
		cin >> h;
		Nan.push_back(h);
	}

	sort(Nan.begin(), Nan.end());
	dfs(0, 0, 0);
	return 0;
}