#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int mtime = 0;

vector<int> P, sum;

int calc() {
	sum.push_back(P[0]);
	for (int i = 1; i < P.size(); i++) {
		sum.push_back(sum.back() + P[i]);
	}
	
	for (int i = 0; i < sum.size(); i++) {
		mtime += sum[i];
	}

	return mtime;
}

int main() {
	cin >> N;
	int p;
	for (int i = 0; i < N; i++) {
		cin >> p;
		P.push_back(p);
	}
	sort(P.begin(), P.end());

	cout << calc() << "\n";
}