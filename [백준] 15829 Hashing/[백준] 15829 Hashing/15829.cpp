#include <iostream>
#include <string>
using namespace std;

const int r = 31;
const long M = 1234567891;
int L;
string str;

long hashing() {
	long h = 0;
	long m = 1;
	for (int i = 0; i < L; i++) {
		h = (h + ((str[i] - 'a' + 1) * m)) % M;
		m = m * r % M;
	}
	return h;
}

int main() {
	cin >> L;
	cin >> str;
	cout << hashing();
}