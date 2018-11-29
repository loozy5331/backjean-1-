#include <iostream>
#include <cstring>
using namespace std;

int powerNums[101];
int ret[101];

int main() {
	for (int i = 0; i < 101; ++i) 
		powerNums[i] = (i+1)*(i+1);
	int M, N;
	cin >> M >> N;
	memset(ret, -1, sizeof(ret));
	int cnt = 0;
	for (int i = 0; i < 101; ++i) {
		if (M <= powerNums[i] && powerNums[i] <= N) {
			ret[cnt++] = powerNums[i];
		}
	}
	if (ret[0] == -1) { cout << -1; exit(0); }
	
	int SumNum = 0;
	for (int i = 0; i < cnt; ++i) 
		SumNum += ret[i];
	
	cout << SumNum << endl;
	cout << ret[0];


}