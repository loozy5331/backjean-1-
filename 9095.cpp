#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
vector<int> nums;
int cache[12];

int kindOfN(int remain) {
	// ±âÀú
	if (remain == 0) return 1;
	else if (remain < 0) return 0;
	int& ret = cache[remain];
	if (ret != -1) return ret;
	int sum = 0;
	for (int i = 1; i <= 3; ++i) {
		sum += kindOfN(remain - i);
	}
	return ret = sum;
}

int main()
{
	int N, temp;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> temp;
		nums.push_back(temp);
	}
	for (int i = 0; i < N; ++i) {
		memset(cache, -1, sizeof(cache));
		cout << kindOfN(nums[i]) << endl;
	}

	
	return 0;
}