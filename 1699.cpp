#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int INF = 987654321;
int powerNums[320];
int cache[100001];

int minimumPower(int n) {
	if (n == 0) return 0;
	int& ret = cache[n];
	if (ret != -1) return ret;
	int minCount = INF;
	for (int i = 1; i < 320; ++i) {
		if (n - powerNums[i] < 0) break;
		minCount = min(minCount, minimumPower(n - powerNums[i]) + 1);
	}
	return ret = minCount;
}

int main() {
	int N;
	cin >> N;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < 320; ++i) 
		powerNums[i] = pow(i, 2);
	cout << minimumPower(N);
}