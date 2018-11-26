#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> fiboList;

int main()
{
	int N;
	scanf("%d", &N);
	if (N == 0)
	{
		printf("%d", 0);
		return 0;
	}
	if (N == 1)
	{
		printf("%d", 1);
		return 0;
	}
	fiboList.push_back(0);
	fiboList.push_back(1);
	for (int i = 2; i < N+1; i++)
		fiboList.push_back(fiboList[i - 1] + fiboList[i-2]);
	
	printf("%d\n", fiboList[N]);
	return 0;
}