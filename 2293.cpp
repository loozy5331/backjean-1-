#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, k;
vector<int> coins;
int cache[101][10001];
int kind(int n, int k) {
	if (n == N) return (k == 0 ? 1 : 0);
	if (k < 0) return 0;
	int& ret = cache[n][k];
	if (ret != -1) return ret;
	int result = kind(n + 1, k);
	if (k - coins[n] >= 0) result += kind(n, k - coins[n]);
	return ret = result;
}

int main() {
	cin >> N >> k;
	coins.resize(N);
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < N; ++i)
		cin >> coins[i];
	cout << kind(0, k);
}