#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

const int MAXNUM = 987654321;
int houses[1001][3];
int cache[1001][3]; // n, start, 

int minHousePrice1(int n, int color, int MaxNum)
{
	if (n == MaxNum) return houses[n][color]; // 종료조건
	if (cache[n][color] != -1) return cache[n][color]; // 캐시 확인
	int minNum = MAXNUM;
	for (int i = 0; i < 3; i++)
		if (color != i)
			minNum = min(minNum, minHousePrice1(n + 1, i, MaxNum));
	return cache[n][color] = houses[n][color] + minNum;
}


int main()
{
	int N, result;
	scanf("%d", &N);
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &houses[i][j]);
		}
	}
	result = min(minHousePrice1(0, 0, N-1), minHousePrice1(0, 1, N-1));
	result = min(result, minHousePrice1(0, 2, N-1));
	printf("%d", result);
	
	return 0;
}