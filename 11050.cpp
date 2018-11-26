#include <cstdio>
using namespace std;

int ehang(int n, int k)
{
	if (n == k || k == 0)
		return 1;
	return ehang(n - 1, k) + ehang(n - 1, k - 1);
}

int main()
{
	int first, second;
	scanf("%d %d", &first, &second);
	printf("%d", ehang(first, second));
}