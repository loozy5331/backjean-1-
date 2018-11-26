#include <iostream>
using namespace std;

int drop[4];
int ride[4];
int currNum[4];

int main()
{
	for (int i = 0; i < 4; ++i)
		cin >> drop[i] >> ride[i];
	
	currNum[0] = 0;
	for (int i = 1; i < 5; ++i)
		currNum[i] = currNum[i - 1] + ride[i - 1] - drop[i - 1];
	int maxNum = 0;
	for (int i = 1; i < 5; ++i)
		if (currNum[i] > maxNum)
			maxNum = currNum[i];
	cout << maxNum;
}