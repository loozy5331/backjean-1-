#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<long long> nums(N+1);
	vector<long long> cache(N+1, 0);
	for (int i = 0; i < N; ++i)
		cin >> nums[i];
	
	long long MAXNUM = cache[0] = nums[0];
	for (int i = 1; i < N; ++i) {
		long long temp = cache[i - 1] + nums[i]; // 지금까지의 최대를 포함했을 때와
		cache[i] = max(temp, nums[i]); // 포함하지 않았을 때,
		MAXNUM = max(MAXNUM, cache[i]); // 전체 최대값
	}
	cout << MAXNUM << '\n';
}