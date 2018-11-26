#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
vector<string> posableNum;

int main() {
	for (int i = 1; i < 9; ++i) {
		for (int j = 1; j < 9; ++j) {
			for (int k = 1; k < 9; ++k) {
				if (i != j && j != k && i != k) {
					string temp = to_string(i * 100 + j * 10 + k);
					posableNum.push_back(temp);
				}
			}
		}
	}
	int size = posableNum.size();
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string tempN;
		int strike, ball;
		cin >> tempN >> strike >> ball;
		char first = tempN[0];
		char second = tempN[1];
		char third = tempN[2];

	}
}