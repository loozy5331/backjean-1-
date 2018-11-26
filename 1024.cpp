#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

long long int N, L;

// 정수인지를 확인하는 함수.
bool checkInteger(long long int num, long long int L) {
	long long int inum = (num - L *(L - 1)/2)/L;
	//double idnum = (double)inum;
	double dnum = (num - L*(L - 1)/2.) / L;
	if (fabs(dnum - inum) < 1e-10) {
		return true;
	}
	return false;
}

int main()
{
	vector<int> ret;
	bool flag = false;
	cin >> N >> L;
	for (long long int i = L; i < 101; ++i) {
		long long int inum = (N - i *(i - 1) / 2) / i;
		if (inum < 0) break;
		if (checkInteger(N, i)) {
			flag = true;
			for (int j = inum; j < (inum + i); ++j)
				ret.push_back(j);
		}
		if (flag) break;
	}

	if (flag) {
		for (int i = 0; i < ret.size(); ++i) {
			if (i != ret.size() - 1)
				cout << ret[i] << " ";
			else 
				cout << ret[i];
		}
	} else {
		cout << -1;
	}
	
	return 0;
}