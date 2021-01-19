#include <iostream>

using namespace std;

int N;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int sum = i;
		int quo = i;
		for (int j = 0; quo > 0; j++) {
			sum += quo % 10;
			quo = quo / 10;
		}
		
		if (sum == N) {
			cout << i;
			return 0;
		}
	}
	cout << 0;

	return 0;
}