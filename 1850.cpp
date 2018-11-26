#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	gcd(b, a  % b);
}

int main() 
{
	int first, second;
	scanf("%d %d", &first, &second);

	return 0;
}