#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int cache[1001][10];

int slopeNum(int n, int prevN) {
	if (n == 0) return 1;
	int& ret = cache[n][prevN];
	if (ret != -1) return ret;
	int result = 0;
	for (int i = prevN; i < 10; ++i) {
		result += slopeNum(n - 1, i)%10007;
	}
	return ret = result % 10007;
}

int main() {
	int N;
	memset(cache, -1, sizeof(cache));
	cin >> N;
	cout << slopeNum(N, 0);
}