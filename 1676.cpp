#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, Five=0, Two=0;
	cin >> N;
	if (N == 0) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= N; ++i) {
		int tmpFive = i;
		int tmpTwo = i;
		if (i % 5 == 0)
			while (tmpFive % 5 == 0) {
				tmpFive /= 5;
				Five++;
			}
		if (i % 2 == 0)
			while (tmpTwo % 2 == 0) {
				tmpTwo /= 2;
				Two++;
			}
	}
	
	cout << min(Two, Five);
	return 0;
}