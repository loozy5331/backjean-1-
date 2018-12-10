#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int nums[1001];
int cache[1001];

int maximum(int n, int maxN) {
	if (n == N) return 0;
	int& ret = cache[n];
	if (ret != -1) return ret;
	int maxNum = 0;
	
	return ret = maxNum;

}

int main() {
	cin >> N;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < N; ++i)
		cin >> nums[i];
	cout << maximum(0, 0);

	
}