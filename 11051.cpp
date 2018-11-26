#include <cstdio>
#include <cstring>
using namespace std;

int cache[1001][1001];

int ehang(int n, int k)
{
	if (n == k || k == 0) return 1;
	if (cache[n][k] != -1) return cache[n][k];
	cache[n][k] = ehang(n - 1, k) + ehang(n - 1, k - 1);
	if (cache[n][k] > 10007)
		cache[n][k]= cache[n][k] % 10007;
	return cache[n][k];
}

int main()
{
	memset(cache, -1, sizeof(cache));
	int first, second;
	scanf("%d %d", &first, &second);
	int ret = ehang(first, second) % 10007;
	printf("%d", ret);
	return 0;
}