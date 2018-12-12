#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

ll sums[1000001];
ll remain[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll N, M, count = 0;
	cin >> N >> M;
	sums[0] = 0;
	remain[0]++;
	for (int i = 1; i <= N; ++i) {
		ll temp;
		cin >> temp;
		sums[i] = (sums[i-1] + temp) % M;
	}
	for (int i = 1; i <= N; ++i) {
		remain[sums[i]]++;
	}
	for (int i = 0; i < 1000; ++i) {
		count += (remain[i] * (remain[i] - 1)) / 2;
	}
	cout << count;
	
}