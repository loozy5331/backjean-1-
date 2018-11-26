#include <cstdio>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	gcd(b, a % b);
}

int main()
{
	int first, second;
	scanf("%d %d", &first, &second);
	printf("%d\n%d", gcd(first, second),
		first*(second / gcd(first, second)));
}