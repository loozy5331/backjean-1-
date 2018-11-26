#include <iostream>
#include <cstring>
#include <algorithm>
#define uint unsigned int
using namespace std;

uint cache[10][101];
uint MOD = 1000000000;

uint stairLen(int beforeNum, int currLen) {
	// 기저사건
	if (currLen == 0) return 1;
	uint &ret = cache[beforeNum][currLen];
	if (ret != -1) return ret;
	uint sumNum = 0;
	for (int i = 0; i < 10; ++i)
		if (abs(i - beforeNum) == 1) 
			sumNum = (sumNum + stairLen(i, currLen - 1)) % MOD;
	return ret = sumNum % MOD;
}

int main()
{
	// 길이.
	int len, result = 0;
	cin >> len;
	//초기화
	memset(cache, -1, sizeof(cache));
	// 맨 처음은 0이 될 수 없기 때문에 따로 계산.
	for (int i = 1; i < 10; ++i)
		result = (result + stairLen(i, len - 1)) % MOD;
	cout << result % MOD;
	return 0;
}