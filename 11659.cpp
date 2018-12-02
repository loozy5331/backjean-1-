#include <iostream>
using namespace std;

int nums[100001];
int pSum[100002];
int result[100001];

int main() {
	cin.tie(NULL);
	int N, M, cnt=0;
	int tempI, tempJ;
	cin >> N >> M;

	pSum[0] = 0;
	for (int i = 0; i < N; ++i) {
		cin >> nums[i];
		pSum[i + 1] = pSum[i] + nums[i];
	}
	for (int i = 0; i < M; ++i) {
		cin >> tempI >> tempJ;
		result[cnt++] = pSum[tempJ] - pSum[tempI-1];
	}
	for (int i = 0; i < M; ++i) {
		cout << result[i] << '\n';
	}
	
}