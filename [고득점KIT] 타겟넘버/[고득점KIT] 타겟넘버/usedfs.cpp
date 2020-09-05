#include <string>
#include <vector>

using namespace std;

int nsize;
int answer;

void dfs(int n, int t, int sum, vector<int> num) {
	if (n == nsize) {
		if (sum == t) {
			answer++;
		}
		return;
	}

	dfs(n + 1, t, sum + num[n], num);
	dfs(n + 1, t, sum - num[n], num);
	return;
}

int solution(vector<int> numbers, int target) {
	answer = 0;
	nsize = numbers.size();

	dfs(0, target, 0, numbers);

	return answer;
}