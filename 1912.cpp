#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
const int MAX_N = 100001;
int nums[MAX_N];
int cache[MAX_N];

int main() {
	int result=-1e9;
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> nums[i];
	if (N == 1) { cout << nums[0]; exit(0); }
	cache[0] = nums[0];
	for (int i = 1; i < N; ++i) {
		int temp = cache[i - 1] + nums[i];
		cache[i] = max(temp, nums[i]);
		result = max(result, cache[i]);
	}
	cout << result;
}