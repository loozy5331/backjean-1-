#include <iostream>
#include <cstring>
using namespace std;

int N;
int cache[1000001];

int tiles(int w) {
	if (w == 0) return 1;
	if (w < 0) return 0;
	int& ret = cache[w];
	if (ret != -1) return ret;
	int result = tiles(w - 1)%15746;
	result += tiles(w - 2) % 15746;
	return ret = result % 15746;
}

int main() {
	cin >> N;
	memset(cache, -1, sizeof(cache));
	cout << tiles(N);

}