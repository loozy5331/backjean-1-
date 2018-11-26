#include <cstdio>

int Nums[123456 * 2 + 1];
int answer[123456 * 2 + 1];
int length[123456 + 1];


int main()
{
	int N, count = 0, lcount=0;
	while (true){
		scanf("%d", &N);
		if (N == 0)
			break;
		for (int i = 0; i < 2 * N + 1; i++)
			Nums[i] = true;
		Nums[0] = false;
		Nums[1] = false;
		for (int i = 2; i < 2 * N + 1; i++) {
			if (Nums[i] == true && (i > N && i <= 2 * N))
				answer[count++] = i;
			if (Nums[i] == true) {
				for (int j = i; j < 2 * N + 1; j += i)
					Nums[j] = false;
			}
		}
		length[lcount++] = count;
		count = 0;
	}

	for (int i = 0; i < lcount; i++)
		printf("%d\n", length[i]);
	return 0;
}