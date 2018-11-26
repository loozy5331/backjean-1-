#include <iostream>
#include <algorithm>
using namespace std;

int N;
int height[100001];
int histogram(int s, int e) {
	if (s == e) return 0;
	if (s + 1 == e) return height[s];

	int mid = (s + e) / 2;
	int result = max(histogram(s, mid), histogram(mid, e));

	int h = height[mid], w = 1, l = mid, r = mid;
	while (r - l + 1 < e - s) {
		int p = (l > s ? min(h, height[l - 1]) : -1);
		int q = (r < e - 1 ? min(h, height[r + 1]) : -1);
		if (p >= q) {
			h = p;
			l--;
		}
		else {
			h = q;
			r++;
		}
		result = max(result, ++w * h);
	}
	return result;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> height[i];
	cout << histogram(0, N);
}
