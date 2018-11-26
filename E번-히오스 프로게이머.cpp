#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> levels;
	int N, K;
	cin.tie(NULL);
	cin >> N >> K;
	levels.resize(N);
	for (int i = 0; i < N; ++i) 
		cin >> levels[i];
	long long lo = 0, hi = 10000000000;
	long long mid;
	while (lo + 1< hi) {
		mid = (lo + hi) / 2;
		long long sumNum = 0;
		for (int i = 0; i < N; ++i) {
			if (mid > levels[i]) sumNum += (mid - levels[i]);
		}
		if (sumNum > K) hi = mid;
		else lo = mid;
	}
	cout << lo;
}