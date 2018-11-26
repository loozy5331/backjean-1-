#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

int N;
int cache[301][25][25];

int inner(int n, int k, int next) {
	if (k == 0) return n == N ? 1 : 0;
	if (k < 0 || n > N) return 0;
	int& ret = cache[n][k][next];
	if (ret != -1) return ret;
	long long result = 0;
	for (int i = next; i >= 0; --i) {
		result += inner(i, k-1, next-1);
	}
	return ret = result;
}

int solution(int n, int k) {
	int answer = 0;
	N = n;
	memset(cache, -1, sizeof(cache));

	answer = inner(0, k, 24);
	return answer;
}

int main() {
	cout << solution(9, 3);
}