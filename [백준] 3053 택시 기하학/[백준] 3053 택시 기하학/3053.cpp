#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double R;
	double pi = M_PI;
	cin >> R;
	double uclyde = R * R * pi;
	double unuclyde = 2 * R * 2 * R / 2;

	cout << fixed;
	cout.precision(6);

	cout << uclyde << endl << unuclyde << endl;

	return 0;

}