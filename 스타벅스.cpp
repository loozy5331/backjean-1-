#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	vector<string> Answer;
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int N, M, K, sum=0;
		map<int, int> cmap;
		cin >> N >> M >> K;
		for (int i = 0; i < N; ++i) {
			int cofNum;
			cin >> cofNum;
			cmap[cofNum]++;
		}
		for (int i=1;i<M+1;++i)
		{
			int price;
			cin >> price;
			sum += price * cmap[i];
		}
		if (sum > K)
			Answer.push_back("N");
		else
			Answer.push_back("Y");

	}
	for (int i = 0; i < Answer.size(); ++i)
	{
		cout << "Case #" << i + 1 << endl;
		cout << Answer[i] << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}