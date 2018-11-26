#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int nums[10000];
	memset(nums, 0, sizeof(nums));
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int n;
		scanf("%d", &n);
		nums[n-1]++;
	}
	for (int i = 0; i < 10000; i++) {
		if (nums != 0) {
			for (int j = 0; j < nums[i]; j++)
				printf("%d\n", i + 1);
		}
	}

}