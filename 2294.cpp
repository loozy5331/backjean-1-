#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, K, INF=987654321;
int cost[101];
int cache[101][10001];

int coin(int n, int k) {
	// ���� ���
	if (n == N) return (k == 0 ? 0 : INF);
	int& ret = cache[n][k];
	if (ret != -1) return ret;
	int result = coin(n + 1, k);
	if (k >= cost[n]) 
		// k�� cost[n]���� ������ �Ʒ����� �ٷ� return �ϱ� ������ n���� ���� Ż���� ��.
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