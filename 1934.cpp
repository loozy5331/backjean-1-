#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	gcd(b, a % b);
}

int main() 
{
	int N, ret;
	int first[1001], second[1001];

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &first[i], &second[i]);
	for (int i = 0; i < N; i++) {
		ret = first[i]*second[i]/gcd(first[i], second[i]);
		printf("%d\n", ret);
	}
}