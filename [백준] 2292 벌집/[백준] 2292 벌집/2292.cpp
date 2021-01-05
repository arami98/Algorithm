#include <iostream>

using namespace std;

int N;

int main() {
	cin >> N;
	int layer = 1;
	int sum = 1;

	for (sum; sum < N; layer++) {
		sum += 6 * layer;
	}

	cout << layer;
}