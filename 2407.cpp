#include <iostream>
#include <cstring>
using namespace std;

int N, M;
unsigned long long cache[101][101];

unsigned long long Ehang(int n, int m) {
	if (n == m || m == 0) return 1;
	unsigned long long& ret = cache[n][m];
	if (ret != -1) return ret;
	return ret = Ehang(n - 1, m - 1) + Ehang(n - 1, m);
}

int main() {
	//cin >> N >> M;
	memset(cache, -1, sizeof(cache));
	for (int i = 1; i < 100; ++i) {
		for (int j = 1; j < 100; ++j) {
			if(i >= j) cout << Ehang(i, j) << endl;
		}
	}
}