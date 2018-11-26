#include <iostream>
#include <cstring>
using namespace std;

int N;
int cache[3001][3];
int three(int n, int cnt) {
	if (cnt == 0) return (n == 0 ? 1 : 0);
	if (n < 0) return 0;
	int& ret = cache[n][cnt];
	if (ret != -1) return ret;
	int result = 0;
	for (int i = 0; i < 1000; ++i) {
		result += three(n - 3 * i, cnt - 1);
	}
	return ret = result;
}


int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N;
	cout << three(N - 9, 3);
}