#include <iostream>
using namespace std;

int main() {
	int N;
	bool cups[3] = { false, };
	cups[0] = true;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int tempA, tempB;
		cin >> tempA >> tempB;
		if (cups[tempA-1] == true || cups[tempB - 1] == true) {
			swap(cups[tempA - 1], cups[tempB - 1]);
		}
	}
	for (int i = 0; i < 3; ++i) {
		if (cups[i] == true) cout << i + 1;
	}
}