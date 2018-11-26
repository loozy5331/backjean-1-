#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N, ret = 9;
	cin >> N;
	if (N < 10)
		cout << N;
	string strN = to_string(N);
	int strlen = strN.size();
	

	return 0;
}