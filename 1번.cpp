#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cmath>
using namespace std;

string solution(string rule, string A, string B) {
	string answer = "";
	vector<int> v;
	map<char, int> index;
	map<int, char> revindex;

	int rule_len = rule.size();
	for (int i = 0; i < rule.size(); ++i) {
		index[rule[i]] = i;
		revindex[i] = rule[i];
	}

	int A_size = A.size();
	int deA = 0;
	for (int i = 0; i < A_size; ++i) {
		deA += index[A[i]] * pow(rule_len, A_size - 1 - i);
	}

	int B_size = B.size();
	int deB = 0;
	for (int i = 0; i < B_size; ++i) {
		deB += index[B[i]] * pow(rule_len, B_size - 1 - i);
	}

	int temp = deA - deB;
	if (temp == 0) return rule[0] + "";
	while (temp >= rule_len) {
		int remain = temp % rule_len;
		v.push_back(remain);
		temp /= rule_len;
	}
	v.push_back(temp);
	for (int i = v.size() - 1; i >= 0; --i) {
		answer += revindex[v[i]];
	}
	return answer;
}

int main() {
	cout << solution("ab", "ba", "a");
}

