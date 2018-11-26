#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int start[10001];
int last[10001];
int cache[10001];

int maxLen(int s) {
	if (s == N - 1) return 0;
	int& ret = cache[s];
	if (ret != -1) return ret;
	int length = 0;
	for (int next = s + 1; next < N-1; ++next) {
		if (last[s] > start[next]) {
			length = max(length, last[next] - start[s]);
		}
		else {
			length += maxLen(next);
			break;
		}
	}
	return ret = length;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> start[i] >> last[i];
	}
	cout << maxLen(0);
	return 0;
}