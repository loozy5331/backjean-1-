#include <iostream>
#include <iomanip>
using namespace std;

double padoban[101];
double result[101];

int main() {
	int N;
	cin >> N;
	padoban[0] = padoban[1] = padoban[2] = 1;
	for (int i = 3; i < 100; ++i) {
		padoban[i] = padoban[i - 2] + padoban[i - 3];
	}
	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		result[i] = padoban[temp - 1];
	}
	cout << fixed << setprecision(0);
	for (int i = 0; i < N; ++i) {
		cout << result[i] << endl;
	}
}