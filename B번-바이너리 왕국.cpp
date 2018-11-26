#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	int N, M, mask=0;
	int tempA, tempB;
	vector<int> ret;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> tempA;
		if (tempA == 1) {
			mask |= (1 << i);
		}
	}
	for (int i = 0; i < M; ++i) {
		cin >> tempA;
		if (tempA == 0) {
			int indi = 0;
			int flag = true;
			for (int i = 0; i < N; ++i) {
				if (flag && (mask & (1 << i))) {
					flag = false;
					indi++;
				}
				else if((mask & (1 << i)) == 0) {
					flag = true;
				}
			}
			ret.push_back(indi);
		}
		else {
			cin >> tempB;
			mask |= (1 << tempB);
		}
	}

	for (int i = 0; i < ret.size(); ++i) {
		cout << ret[i] << endl;
	}
	
}