#include <iostream>
#include <map>
#define MAX 10000001
using namespace std;

int N, M;
int arr_p[MAX];
int arr_n[MAX];

map<int, int> card;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		card[n]++;
		/*if (n >= 0)
			arr_p[n]++;
		else
			arr_n[n*(-1)]++;*/
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;
		cout << card[n] << " ";
		/*if (n >= 0)
			cout << arr_p[n] << " ";
		else
			cout << arr_n[n*(-1)] << " ";*/
	}

	return 0;
}