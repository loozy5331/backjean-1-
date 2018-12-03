#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long block[100001];

long long histogram(int s, int e) {
	if (s == e) return 0;
	if (s + 1 == e) return block[s];
	long long mid = (s + e) / 2;
	long long result = max(histogram(s, mid), histogram(mid, e));
	long long w = 1, h = block[mid], l = mid, r = mid;
	while (r - l + 1 < e - s) {
		long long p = (l > s) ? min(h, block[l - 1]) : -1;
		long long q = (r < e - 1) ? min(h, block[r + 1]) : -1;
		if (p >= q) {
			h = p;
			l--;
		}
		else {
			h = q;
			r++;
		}
		result = max(result, (++w)*h);
	}
	return result;
}

int main() {
	int T, cnt =0;
	vector<long long> ret;
	while (true) {
		cin >> T;
		if (T == 0) break;
		cnt++;
		for (int i = 0; i < T; ++i) 
			cin >> block[i];
		ret.push_back(histogram(0, T));
	}
	for (int i = 0; i < cnt; ++i) {
		cout << ret[i] << endl;
	}
}