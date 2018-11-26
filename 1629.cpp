#include <iostream>
using namespace std;

long long power(int a, int b, int c) {
	if (b == 1) return a%c;
	if (b % 2 == 1) return (power(a, b - 1, c) * a)%c;
	long long result = (power(a, b / 2, c)%c)*(power(a, b / 2, c)%c);
	return result%c;
}

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	cout << power(A, B, C);
}