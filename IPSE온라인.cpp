#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char** argv)
{
	int T, test_case;
	vector<int> resultMP;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int monsterNum;
		cin >> monsterNum;
		vector<int> levels;
		for (int j = 0; j<monsterNum; ++j)
		{
			int level; cin >> level;
			levels.push_back(level);
		}
		int MP = 20000;
		for (int j = 0; j<levels.size(); ++j)
		{

			if (levels[j] <= 3 || levels[j] >= 178) break;
			if (levels[j] <= 40) {
				if (MP - 720 < 0) break;
				else MP -= 720;
			}
			else {
				int plusMP = (levels[j] - 40 - 1) / 8;
				if ((MP - plusMP * 80 - 800) < 0) break;
				else MP -= (plusMP * 80 + 800);
			}
		}
		resultMP.push_back(MP);
		
	}
	for (int i = 0; i<resultMP.size(); ++i)
	{
		cout << resultMP[i] << endl;
	}
	return 0;//Your program should return 0 on normal termination.
}