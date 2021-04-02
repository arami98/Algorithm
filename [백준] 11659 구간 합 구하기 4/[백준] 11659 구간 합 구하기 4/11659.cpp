#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<int> sum;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M;

	cin >> N >> M;
	sum.push_back(0);
	for (int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
		sum.push_back(num + sum.at(i - 1));
	}

	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		cout << sum.at(n2) - sum.at(n1 - 1) << "\n";
	}
	return 0;
}