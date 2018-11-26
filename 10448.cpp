#include <iostream>
#include <vector>
using namespace std;

int EurekaNum[41];
vector<int> ret;

int main() {
	// 유레카 수 채우기
	for (int i = 1; i < 40; ++i) {
		EurekaNum[i] = i*(i + 1) / 2;
	}

	int N;
	cin >> N;
	ret.resize(N + 1, 0);
	for (int i = 0; i < N; ++i) {
		int tempN;
		cin >> tempN;
		for (int a = 1; a < 40; ++a) {
			for (int b = 1; b < 40; ++b) {
				for (int c = 1; c < 40; ++c) {
					if (tempN == EurekaNum[a] + EurekaNum[b] + EurekaNum[c]) {
						ret[i] = 1;
					}
				}
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << ret[i] << endl;
	}

}