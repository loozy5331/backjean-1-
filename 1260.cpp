#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

map<int, vector<int>> m;

bool flag[1001] = {false, };
stack<int> s;
queue<int> q;

void dfs(int start) {
	s.push(start);
	while (!s.empty()) {
		int temp = s.top();
		cout << temp << " ";
		s.pop();
		flag[temp] = true;
		for (int i = 0; i < m[temp].size(); ++i) {
			if (flag[m[temp][i]] == false) {
				dfs(m[temp][i]);
			}
		}
	}
}

void bfs(int start) {
	q.push(start);
	while (!q.empty()){
		int temp = q.front();
		cout << temp << " ";
		q.pop();
		flag[temp] = true;
		for (int i = 0; i < m[temp].size(); ++i) {
			if (flag[m[temp][i]] == false) {
				q.push(m[temp][i]);
				flag[m[temp][i]] = true;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	int N, E, startN, tempS, tempF;
	cin >> N >> E >> startN;
	for (int i = 0; i < E; ++i) {
		cin >> tempS >> tempF;
		m[tempS].push_back(tempF);
		m[tempF].push_back(tempS);
	}
	// Á¤·Ä
	for (int i = 1; i < N+1; ++i) {
		sort(m[i].begin(), m[i].end());
	}
	dfs(startN);
	cout << "\n";
	memset(flag, false, sizeof(flag));
	bfs(startN);
	cout << "\n";
	return 0;
}