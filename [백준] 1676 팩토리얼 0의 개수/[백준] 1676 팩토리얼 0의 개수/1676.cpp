#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, temp;
	int two = 0;
	int five = 0;
	cin >> N;

	for (int i = 1; i < N + 1; i++) {
		temp = i;
		while (temp != 0) {
			if (temp % 2 == 0) {
				two++;
				temp /= 2;
			}
			else
				break;
		}
			
		temp = i;
		while (temp != 0) {
			if (temp % 5 == 0) {
				five++;
				temp /= 5;
			}
			else
				break;
		}
	}

	cout << min(two, five);
	return 0;
}