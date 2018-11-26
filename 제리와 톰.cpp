#include <iostream>
#include <cstring>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int func(int A, int B) {
	int ret = B - A;
	return ret;
}

int main()
{
	int A, B;
	cin >> A >> B;
	int ret = func(A, B);
	cout << ret/gcd(ret, B) << " " << B/gcd(ret, B);
	return 0;
}