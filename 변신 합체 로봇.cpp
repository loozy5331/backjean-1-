#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	vector<long long > answer;
	int T, test_case;
	int robotNums[20];
	for (int i = 0; i < 20; ++i){
		robotNums[i] = i + 1;
	}
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int N;
		long long int ret = 1;
		set<int> canNew;
		set<int> cantNew;
		multiset<int> all;
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			int step;
			cin >> step;
			for (int j = 0; j < step; ++j)
			{
				int robotNum;
				cin >> robotNum;
				if (j == step - 1) {
					cantNew.insert(robotNum);
					all.insert(robotNum);
					break;
				}
				canNew.insert(robotNum);
				all.insert(robotNum);
			}
		}
		for (set<int>::iterator sit= cantNew.begin(); sit != cantNew.end(); ++sit)
		{
			if (!canNew.count(*sit)) {
				ret *= (*sit);
			}
		}
		for (int i = 0; i < 20; ++i)
		{
			if (all.count(robotNums[i]) == 0)
				ret *= robotNums[i];
		}
		answer.push_back(ret);
	}

	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << endl;
	}
	return 0;//Your program should return 0 on normal termination.
}