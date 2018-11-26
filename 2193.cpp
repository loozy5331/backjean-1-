#include <iostream>
#include <cstring>
using namespace std;

long long int cache[91][2];

long long int pinaryN(int n, int previous) {
	if (n == 1) return 1;
	long long int& ret = cache[n][previous];
	if (ret != -1) return ret;
	long long int sum = 0;
	if (previous == 1) sum = pinaryN(n - 1, 0);
	else sum = pinaryN(n - 1, 0) + pinaryN(n - 1, 1);
	return ret = sum;
}

int main() {
	int N;
	memset(cache, -1, sizeof(cache));
	cin >> N;
	cout << pinaryN(N, 1);

	return 0;
}