#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, num=0, MaxNum=0;

	scanf("%d", &N);
	int *NArr = new int[N + 1];
	int *copyNArr = new int[N + 1];
	for (int i = 0; i < N; i++){
		scanf("%d", &num);
		NArr[i] = num;
		copyNArr[i] = num;
	}
	
	sort(NArr, NArr+N);
	MaxNum = NArr[N-1];
	int *ZeroArr = new int[MaxNum + 3];
	int *OneArr = new int[MaxNum + 3];

	ZeroArr[0] = 1;
	ZeroArr[1] = 0;
	OneArr[0] = 0;
	OneArr[1] = 1;

	for (int i = 2; i < MaxNum + 1; i++) {
		ZeroArr[i] = ZeroArr[i - 1] + ZeroArr[i - 2];
		OneArr[i] = OneArr[i - 1] + OneArr[i - 2];
	}
		
	for (int i = 0; i < N; i++)
	{
		int num = copyNArr[i];
		printf("%d %d\n", ZeroArr[num], OneArr[num]);
	}
	delete[] NArr;
	delete[] ZeroArr;
	delete[] OneArr;
	delete[] copyNArr;
	return 0;
}