#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int fruits[1001];

int main()
{
	int N, L;
	cin >> N >> L;
	for (int i = 0; i < N; ++i) {
		cin >> fruits[i];
	}
	sort(fruits, fruits + N);
	for (int i = 0; i < N; ++i) {
		if (fruits[i] <= L) L++;
		else break;
	}
	cout << L;

	return 0;
}