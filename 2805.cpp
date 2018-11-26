#include <iostream>
using namespace std;

int N, H;
int height[1000001];

int main()
{
	cin.tie(NULL);
	cin >> N >> H;
	for (int i = 0; i < N; ++i) 
		cin >> height[i];
	int lo=0, hi=2000000001;
	// 최소 lo는 되어야 조건을 만족할 수 있음.
	while (lo + 1 < hi) {
		long long sum = 0;
		int mid = (lo + hi) / 2;
		// 난 반대로 시뮬레이션 함ㅠ
		for (int i = 0; i < N; ++i) {
			if(height[i] > mid) sum += height[i] - mid;
		}
		if (sum >= H) lo = mid;
		else hi = mid;
		cout << lo << ", " << mid << ", "<< hi << endl;
	}
	cout << lo;
	return 0;
}