#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id) {
	string answer = "";
	string step1 = "";
	string step2 = "";
	string step3 = "";
	string step4 = "";
	string step5 = "";
	string step6 = "";
	string step7 = "";

	step1 = new_id;
	for (int i = 0; i < new_id.length(); i++) {
		if ('A' <= new_id[i] && new_id[i] <= 'Z')
			step1[i] = new_id[i] - ('A' - 'a');
	}
	cout << "step1 >> " << step1 << endl;

	for (int i = 0; i < step1.length(); i++) {
		if (step1[i] == '.')
			step2 += step1[i];
		if (step1[i] == '-')
			step2 += step1[i];
		if (step1[i] == '_')
			step2 += step1[i];
		if (step1[i] >= '0' && step1[i] <= '9')
			step2 += step1[i];
		if (step1[i] >= 'a' && step1[i] <= 'z')
			step2 += step1[i];

	}
	cout << "step2 >> " << step2 << endl;

	for (int i = 0; i < step2.length(); i++) {
		step3 += step2[i];
		if (step2[i] == '.') {
			int j;
			for (j = i + 1; j < step2.length(); j++) {
				if (step2[j] != '.') {
					i = j - 1;
					break;
				}
			}
			if (j == step2.length())
				break;
		}
	}
	cout << "step3 >> " << step3 << endl;

	if (step3.front() == '.')
		step3 = step3.substr(1);
	if (step3.back() == '.')
		step3.pop_back();
	step4 = step3;
	cout << "step4 >> " << step4 << endl;

	if (step4.empty())
		step5 += 'a';
	else
		step5 = step4;
	cout << "step5 >> " << step5 << endl;

	if (step5.length() >= 16) {
		step5.resize(15);
		if (step5.back() == '.')
			step5.pop_back();
	}
	step6 = step5;
	cout << "step6 >> " << step6 << endl;

	if (step6.length() <= 2) {
		while (step6.length() < 3) {
			step6 += step6.back();
		}
	}
	step7 = step6;
	cout << "step7 >> " << step7 << endl;

	answer = step7;

	return answer;
}

int main() {
	cout << solution("...!@BaT#*..y.abcdefghijklm") << endl;

	return 0;
}