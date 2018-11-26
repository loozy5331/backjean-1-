#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool check(vector<int> a) {
	for (int i = 1; i < a.size(); ++i) {
		if (a[i - 1] > a[i])
			return false;
	}
	return true;
}

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	int s_len = skill.size();
	int tree_len = skill_trees.size();

	for (int i = 0; i < tree_len; ++i) {
		bool flag = false;
		vector<int> chec;
		string temp = skill_trees[i];
		for (int j = 0; j < s_len; ++j) {
			for (int k = 0; k < temp.size(); ++k) {
				// 맨 처음 것이 나오지 않으면 성립 x.
				if (j == 0 && skill[j] == temp[k]) {
					break;
				}

				if (skill[j] == temp[k]) {
					chec.push_back(k);
					break;
				}
			}
		}
		if (chec.empty() || !check(chec)) continue;
		else answer++;
	}
	return answer;
}



int main() {
	vector<string> sl = { "BACDE", "CBADF", "AECB", "BDA" };
	string skill = "CBD";
	cout << solution(skill, sl);
	return 0;
}