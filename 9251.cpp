#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

string A, B;
int cache[1001][1001];
int LCS(int as, int bs) {
	if (as == A.size() || bs == B.size()) return 0;
	int& ret = cache[as][bs];
	if (ret != -1) return ret;
	int count = 0;
	if (A[as] == B[bs]) { 
		count++; 
		count += LCS(as + 1, bs + 1);
	}
	count = max(count, LCS(as + 1, bs));
	count = max(count, LCS(as, bs+ 1));
	return ret = count;
}


int main() {
	cin >> A >> B;
	memset(cache, -1, sizeof(cache));
	cout << LCS(0, 0);
}