#include <iostream>
using namespace std;

int coins[11];

int main() {
	int N, K, cnt=0, kind=0;
	cin >> N >> K;
	for (int i = N-1; i >=0 ; --i) {
		cin >> coins[i];
	}
	while (K != 0) {
		if (K - coins[kind] >= 0) {
			K -= coins[kind];
			cnt++;
		}
		else {
			kind++;
		}
	}
	cout << cnt;
}