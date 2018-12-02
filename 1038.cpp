#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool checkNum(int n) {
	bool flag = true;
	string tempStr = to_string(n);
	if (tempStr.size() == 1) return flag;
	// 맨 위의 자리
	int temp = tempStr[0] - '0';
	for (int i = 1; i < tempStr.size();++i) {
		if (temp <= tempStr[i] - '0') {
			flag = false;
			break;
		}
		else {
			temp = tempStr[i] - '0';
		}
	}
	return flag;
}

int main() {
	int N, cnt = 0, ret= 0; 
	cin >> N;
	while (true) {
		if (cnt == N) break;
		if (checkNum(ret)) {
			cnt++;
		}
		ret++;
	}
	cout << ret;
}