#include <iostream>
using namespace std;

int nums[100001];
int pSum[100002];
int ret[100001];

int main() {
	int N, M, cnt=0;
	int tempI, tempJ;
	cin >> N;
	pSum[0] = 0;
	for (int i = 0; i < N; ++i){
		cin >> nums[i];
		pSum[i + 1] = pSum[i] + nums[i];
	}

	cin >> M;
	for (int i = 0; i < M; ++i) {
		cin >> tempI >> tempJ;
		ret[cnt++] = pSum[tempJ] - pSum[tempI-1];
	}
	for (int i = 0; i < M; ++i) {
		cout << ret[i] << '\n';
	}
	

}