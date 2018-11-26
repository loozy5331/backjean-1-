#include <iostream>
#include <cstring>
using namespace std;

int cache[31][31];
int ehang(int n, int k)
{
	if (n == k || k == 0) return 1;
	int& ret = cache[n][k];
	if (ret != -1) return ret;
	return ret = ehang(n - 1, k - 1) + ehang(n - 1, k);
}

int main()
{
	memset(cache, -1, sizeof(cache));
	int n, k;
	cin >> n >> k;
	cout << ehang(n - 1, k - 1);
	return 0;
}