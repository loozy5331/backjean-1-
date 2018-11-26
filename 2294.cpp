#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, K, INF=987654321;
int cost[101];
int cache[101][10001];

int coin(int n, int k) {
	// 기저 사건
	if (n == N) return (k == 0 ? 0 : INF);
	int& ret = cache[n][k];
	if (ret != -1) return ret;
	int result = coin(n + 1, k);
	if (k >= cost[n]) 
		// k가 cost[n]보다 작으면 아래에서 바로 return 하기 때문에 n으로 놔도 탈출을 함.
		result = min(result, coin(n, k-cost[n]) + 1);
	return ret = result;
}

int main()
{
	cin >> N >> K;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < N; ++i) 
		cin >> cost[i];
	int answer = coin(0, K);
	if (answer == INF) cout << "-1";
	else cout << answer;
	return 0;
}