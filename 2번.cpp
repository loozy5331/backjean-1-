#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int solution(vector<vector<int> > envelopes)
{
	int answer = 0;
	vector<int> f;
	vector<int> s;
	sort(envelopes.begin(), envelopes.end());
	for (int i = 0; i < envelopes.size(); ++i) {
		f.push_back(envelopes[i][0]);
		s.push_back(envelopes[i][1]);
	}
	int MaxNum = 0;
	int tempA = f[0], tempB = s[0];
	for (int j = 1; j < envelopes.size(); ++j) {
		int count = 1;
		for (int i = j; i < envelopes.size(); ++i) {
			if (tempA != f[i] && tempB < s[i]) {
				tempA = f[i];
				tempB = s[i];
				count++;
			}
		}
		MaxNum = max(MaxNum, count);
	}
	answer = max(MaxNum, answer);
	return answer;
}

int main() {
	vector<vector<int>> ret;
	vector<int> temp;
	temp.resize(2);
	for (int i = 0; i < 6; ++i) {
		cin >> temp[0] >> temp[1];
		ret.push_back(temp);
	}
	cout << solution(ret);
}
