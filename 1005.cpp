#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int cache[1003];
vector<int> time;
vector<int> first;
vector<int> second;
vector<int> retV;

int minBuildTime(int start)
{
	int &ret = cache[start];
	if (ret != -1) return ret;
	int length = first.size(), maxTime = 0;
	for (int i = length - 1; i >= 0; --i) {
		if (second[i] == start) {
			maxTime = max(maxTime, time[second[i] - 1] + minBuildTime(first[i]));
		}
	}
	// 기저 사건.
	if (maxTime == 0) 
		return ret = time[start - 1];
	// 기저가 아닌 사건.
	else 
		return ret = maxTime;
}

int main()
{
	int TestCase;
	cin >> TestCase;
	for (int t_case = 0; t_case < TestCase; ++t_case)
	{
		// vector 초기화
		memset(cache, -1, sizeof(cache));
		time.clear();
		first.clear();
		second.clear();

		// 입력 받음.
		int factN, rule, lastFact;
		cin >> factN >> rule;
		for (int t = 0; t < factN; ++t) {
			int temp;
			cin >> temp;
			time.push_back(temp);
		}
		for (int r = 0; r < rule; ++r) {
			int N, M;
			cin >> N >> M;
			first.push_back(N);
			second.push_back(M);
		}
		cin >> lastFact;
		retV.push_back(minBuildTime(lastFact));
	}
	// 결과 출력
	for (int i = 0; i < retV.size(); ++i)
	{
		cout << retV[i] << endl;
	}
	return 0;
}