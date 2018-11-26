#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int minN = -1e9;
int N;
int cache[1001];
int prices[10001];

int maxMoney(int n) {
	if (n == 0) return 0;
	if (n < 0) return minN;
	int& ret = cache[n];
	if (ret != -1) return ret;
	int result = minN;
	for (int i = 0; i < N; ++i) {
		result = max(result, maxMoney(n - i - 1) + prices[i]);
	}
	return ret = result;
}

int main() {
	cin >> N;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < N; ++i) 
		cin >> prices[i];
	cout << maxMoney(N);
}