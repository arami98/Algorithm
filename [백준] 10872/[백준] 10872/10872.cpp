#include<iostream>
using namespace std;

int factorial(int n) {
	int fac = 1;
	for (int i = 1; i <= n; i++) {
		fac *= i;
	}
	return fac;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	cout << factorial(n) << "\n";

}