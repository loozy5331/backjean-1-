#include <cstdio>
using namespace std;

long long int arr[91];
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
	}
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i < N + 1; i++)
		arr[i] = arr[i - 1] + arr[i - 2];
	printf("%lld", arr[N]);
	

	return 0;
}