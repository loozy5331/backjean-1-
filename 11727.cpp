#include <iostream>
#include <cstring>
using namespace std;

int W;
int cache[1001];
int tiles(int w) {
	if (w == 0) return 1;
	if (w < 0) return 0;
	int& ret = cache[w];
	if (ret != -1) return ret;
	int result = tiles(w - 1)%10007;
	result += 2 * tiles(w - 2) % 10007;
	return ret = result % 10007;
}

int main() {
	cin >> W;
	memset(cache, -1, sizeof(cache));
	cout << tiles(W);
}