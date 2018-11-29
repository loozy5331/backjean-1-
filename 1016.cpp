#include <iostream>
using namespace std;

int main() {
	long long MIN, MAX;
	cin >> MIN >> MAX;

	long long power_before_MIN = 0;
	long long power_before_MAX = 0;
	for (long long i = 1; i*i <= MAX; ++i) {
		if (i*i <= MIN)
			power_before_MIN++;
		power_before_MAX++;
	}
	cout << (MAX - MIN) - (power_before_MAX - power_before_MIN);
}