#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int wine[10001];
int cache[10001];

int maxWine(int n)
{
	if (n == N-1) return wine[n];
	if (n > N-1) return 0;
	int& ret = cache[n];
	if (ret != -1) return ret;
	return ret = max(max(maxWine(n + 2) + wine[n],
		maxWine(n+3) + wine[n] + wine[n+1]),
		maxWine(n+4) + wine[n+1] + wine[n+2]);
}

int main() 
{
	cin.tie(NULL);
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> wine[i];
	}
	cout << max(maxWine(0), maxWine(1));
	return 0;
}