#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

bool Ns[105] = { false, };
map<int, vector<int>> m;

void warmV(map<int, vector<int>>& m)
{
	queue<int> q;
	q.push(1);
	Ns[1] = true;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		if (!m[temp].empty()) {
			for (int i = 0; i < m[temp].size(); ++i) {
				int next = m[temp][i];
				if (Ns[next] == false) {
					q.push(next);
					Ns[next] = true;
				}
			}
		}
	}
}

int main()
{
	int N, P, cnt = 0;
	cin >> N >> P;
	for (int i = 0; i < P; ++i) {
		int start, next;
		cin >> start >> next;
		m[start].push_back(next);
		m[next].push_back(start);
	}
	warmV(m);
	for (int i = 0; i < N + 1; ++i)
		if (Ns[i] == true)
			cnt++;
	cout << cnt - 1;

	return 0;
}