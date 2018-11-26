#include <iostream>
#include <algorithm>
using namespace std;

int A[51], B[51];

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	sort(A, A + N);
	sort(B, B + N);
	reverse(A, A+N);
	int Sum = 0;
	for (int i = 0; i < N; ++i) {
		Sum += A[i] * B[i];
	}
	cout << Sum;
	return 0;
}