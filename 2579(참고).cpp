#include <iostream>
#include <algorithm>
using namespace std;
int arr[301];
int dp[301];

int main() {
	int i, n, m;
	cin >> n;
	for (i = n; i > 0; i--)
		cin >> arr[i];

	dp[0] = arr[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = arr[1] + arr[3];

	for (i = 4; i <= n; i++) {
		dp[i] = max(arr[i] + dp[i - 2], arr[i] + arr[i - 1] + dp[i - 3]);
	}
	cout << max(dp[n], dp[n - 1]);
	return 0;
}