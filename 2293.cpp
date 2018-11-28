#include <iostream>
#include <cstring>
using namespace std;

int N, K;
int coins[101];
int cache[101][10001];
int kind(int n, int k) {
	if (n == N) return k==0? 1 : 0;
	int& ret = cache[n][k];
	if (ret != -1) return ret;
	int result = kind(n + 1, k);
	if (k - coins[n] >= 0) result += kind(n, k - coins[n]);
	return ret = result;
}

int main() {
	cin >> N >> K;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < N; ++i)
		cin >> coins[i];
	cout << kind(0, K);
}