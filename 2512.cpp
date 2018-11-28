#include <iostream>
using namespace std;

long long N, M;
int cost[10001];
long long SumCost = 0; // 요구하는 총 예산
int maxCost = 0; // 예산 중 최고값

int DivideCost() {
	if (M >= SumCost) return maxCost;
	long long lo = 0, hi = 1000000001;
	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		long long sumNum = 0;
		for (int i = 0; i < N; ++i) {
			if (cost[i] < mid) sumNum += cost[i];
			else sumNum += mid;
		}
		if (M >= sumNum) lo = mid;
		else hi = mid;
	}
	return lo;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> cost[i];
		SumCost += cost[i];
		if (maxCost < cost[i])
			maxCost = cost[i];
	}
	cin >> M;
	cout << DivideCost();
}