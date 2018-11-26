#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int tri[501][501];
int cache[501][501];

int maxTri(int floor, int number, int MaxNum)
{
	if (floor == MaxNum) return tri[floor][number]; // base 조건
	if (cache[floor][number] != -1) return cache[floor][number]; // 불러오기
	int maxNum = 0;
	maxNum = max(maxTri(floor + 1, number, MaxNum), maxTri(floor + 1, number + 1, MaxNum));
	return cache[floor][number] = maxNum + tri[floor][number];
}

int main()
{
	memset(cache, -1, sizeof(cache));
	int N, ret;
	scanf("%d", &N);
	for (int i = 1; i < N+1; i++)
		for (int j = 0; j < i; j++)
			scanf("%d", &tri[i][j]);
	ret = maxTri(0, 0, N);
	printf("%d", ret);
	return 0;
}