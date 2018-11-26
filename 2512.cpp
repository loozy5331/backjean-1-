#include <iostream>
using namespace std;

int N, M;
int cost[10001];
long long SumCost = 0;
int maxCost = 0;

int DivideCost() {
	if (M >= SumCost) return maxCost;
	int lo = 0, hi = 100000001;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
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