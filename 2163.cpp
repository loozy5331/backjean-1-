#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int M, N;
int cache[301][301];
int splitChoco(int m, int n)
{
	if (m == 1 && n == 1) return 1;
	int& ret = cache[m][n];
	if (ret != -1) return ret;
	int MinimumCount = 987654321;
	MinimumCount = min(splitChoco(m / 2, n), splitChoco(m / 2, n));
	return ret = MinimumCount;
}

int main() {
	memset(cache, -1, sizeof(cache));
	cin >> M >> N;
	cout << splitChoco(M, N);
	return 0;
}