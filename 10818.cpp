#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	int N, minNum = 1000000, maxNum = -1000000;
	vector<int> ret;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		ret.push_back(temp);
	}
	
	for (int i = 0; i < N; ++i)
	{
		if (ret[i] > maxNum)
			maxNum = ret[i];
		if (ret[i] < minNum)
			minNum = ret[i];
	}
	
	return 0;
}