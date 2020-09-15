#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > keypad;
pair<int, int> Lpos;
pair<int, int> Rpos;

char push(int bt, string hand) {
	if (bt == 0) // 0�� ��ư ������ ��
		bt = 11;
	int xbt = keypad[bt - 1].first;
	int ybt = keypad[bt - 1].second;
	char phand;

	//���ʹ�ư
	if (ybt == 1) {
		phand = 'L';
		Lpos = make_pair(xbt, ybt);
		return phand;
	}

	//������ ��ư
	if (ybt == 3) {
		phand = 'R';
		Rpos = make_pair(xbt, ybt);
		return phand;
	}

	//��� ��ư
	if (ybt == 2) {
		int Ldis = abs(Lpos.first - xbt) + abs(Lpos.second - ybt);
		int Rdis = abs(Rpos.first - xbt) + abs(Rpos.second - ybt);

		if (Ldis < Rdis) {		//�޼տ� ����
			phand = 'L';
			Lpos = make_pair(xbt, ybt);
		}
		else if (Ldis > Rdis) {		//�����տ� ����
			phand = 'R';
			Rpos = make_pair(xbt, ybt);
		}
		else {		//�Ÿ� ������
			if (hand == "left") {
				phand = 'L';
				Lpos = make_pair(xbt, ybt);
			}
			else {
				phand = 'R';
				Rpos = make_pair(xbt, ybt);
			}
		}
	}

	return phand;
}

string solution(vector<int> numbers, string hand) {
	string answer = "";
	Lpos = make_pair(4, 1);
	Rpos = make_pair(4, 3);

	for (int i = 1; i < 5; i++) {
		for (int j = 1; j < 4; j++) {
			keypad.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < numbers.size(); i++) {
		answer+= push(numbers[i], hand);
	}

	return answer;
}