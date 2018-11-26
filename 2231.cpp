#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int Constructor(int N)
{
	int result = N;
	string strN = to_string(N);
	int strlen = strN.size();
	for (int i = 0; i < strlen; ++i)
		result += (strN[i] - '0');
	return result;
}

int main()
{
	int N, ret = 0;
	cin >> N;
	if (N < 100) {
		for (int i = 0; i < 100; ++i)
			if (N == Constructor(i)) {
				ret = i;
				break;
			}
	}
	else {
		for (int i = (N - 100); i < N; ++i)
		{
			if (Constructor(i) == N) {
				ret = i;
				break;
			}
		}
	}
	if (ret != 0) cout << ret;
	else cout << 0;
	return 0;
}