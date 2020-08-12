#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int a;
	int b;
	int c;
	vector<int> v;

	while (1) {
		cin >> a >> b >> c;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		if (a == 0 && b == 0 && c == 0)
			break;

		sort(v.begin(), v.end());
		if (v.at(0) * v.at(0) + v.at(1) * v.at(1) == v.at(2) * v.at(2))
			cout << "right" << endl;
		else
			cout << "wrong" << endl;

		v.clear();
	}

	return 0;
}