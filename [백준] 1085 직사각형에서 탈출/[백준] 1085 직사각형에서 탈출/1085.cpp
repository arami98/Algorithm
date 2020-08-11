#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


int escape(int X, int Y, int W, int H) {
	vector<int> v;
	v.push_back(H-Y);
	v.push_back(W-X);
	v.push_back(X);
	v.push_back(Y);
	sort(v.begin(), v.end());

	return v.at(0);
}

int main() {
	int x;
	int y;
	int w;
	int h;

	cin >> x >> y >> w >> h;
	cout << escape(x, y, w, h) << endl;
	
	return 0;
}