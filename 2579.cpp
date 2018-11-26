#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int stair[301];
int cache[301];

int maxScore(int here, int oneNum, int MaxNum)
{
	if (here == MaxNum) return stair[here]; // base condition
	if (here > MaxNum) return -10000; // outer layer
	if (cache[here] != -1) return cache[here];	// cache loading
	int maxNum = 0;
	if (oneNum != 1) {
		maxNum = max(maxNum, maxScore(here + 1, oneNum+1, MaxNum));
	}
	maxNum = max(maxNum, maxScore(here + 2, 0, MaxNum));

	return cache[here] = maxNum + stair[here];
}

int main()
{
	int N;
	memset(cache, -1, sizeof(cache));
	memset(stair, -10000, sizeof(stair));
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &stair[i]);
	}
	int ret = max(maxScore(0, 0, N), maxScore(1, 0, N));
	printf("%d", ret);

	return 0;
}