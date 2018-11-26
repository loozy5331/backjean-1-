#include <cstdio>
using namespace std;

long long int gcd(long long int a, long long int b)
{
	if (b == 0)
		return a;
	gcd(b, a % b);
}

int main()
{
	long long int first, second;
	scanf("%lld %lld", &first, &second);
	long long int ret = first*(second / gcd(first, second));
	printf("%lld", ret);
}