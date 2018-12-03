#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MINNUM = -98654321;
long long pSum[1002];
long long cache[1001][1001];
long long ret[1002];

long long partialSum(int s, int e) {
	if (s == e) return 0;
	if (s + 1 == e) return pSum[s];
	long long& ret = cache[s][e];
	if (ret != MINNUM) return ret;

}

int main() {
	int T; cin >> T;
	for (int t = 0; t < T; ++t) {
		int N; cin >> N;
		fill(cache, cache + 1001 * 1001, MINNUM);
		fill(pSum, pSum + 1002, 0);
		for (int i = 0; i < N; ++i) {
			int temp; cin >> temp;
			pSum[i + 1] = pSum[i] + temp;
		}

	}
}