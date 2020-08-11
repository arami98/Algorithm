#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int findX(vector<pair<int, int>> point) {
	if (point.at(0).first == point.at(1).first)
		return point.at(2).first;
	else if (point.at(1).first == point.at(2).first)
		return point.at(0).first;
	else
		return point.at(1).first;
}

int findY(vector<pair<int, int>> point) {
	if (point.at(0).second == point.at(1).second)
		return point.at(2).second;
	else if (point.at(1).second == point.at(2).second)
		return point.at(0).second;
	else
		return point.at(1).second;
}

int main() {
	vector<pair <int, int>> point;
	int p1, p2;
	int x4, y4;
	for (int i = 0; i < 3; i++) {
		cin >> p1 >> p2;
		point.push_back(make_pair(p1, p2));
	}
	x4 = findX(point);
	y4 = findY(point);

	cout << x4 <<" " << y4 << endl;

	return 0;
}