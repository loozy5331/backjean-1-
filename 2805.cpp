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
	// �ּ� lo�� �Ǿ�� ������ ������ �� ����.
	while (lo + 1 < hi) {
		long long sum = 0;
		int mid = (lo + hi) / 2;
		// �� �ݴ�� �ùķ��̼� �Ԥ�
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