#include <cstdio>

int main()
{
	int M, N, count=0;
	int *Nums = new int[1000000];
	int *answer = new int[1000000];
	scanf("%d %d", &M, &N);
	for (int i = 2; i < N +1; i++)
		Nums[i] = true;
	Nums[0] = false;
	Nums[1] = false;
	for(int i=2; i< N+1; i++) {
		if (Nums[i] == true){
			answer[count++] = i;
			for (int j = i; j < N+1; j+=i)
				Nums[j] = false;
		}
	}

	for (int i = 0; i < count; i++)
		if((answer[i] >= M) && answer[i] <= N)
			printf("%d\n", answer[i]);

	return 0;
}