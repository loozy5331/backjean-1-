#include <iostream>
#include <set>
#include <queue>
using namespace std;

set<int> s;
queue<int> q, ret;

int main()
{
	cin.tie(NULL);
	int N, M, temp;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> temp;
		s.insert(temp);
	}

	cin >> M;
	for (int i = 0; i < M; ++i) {
		cin >> temp;
		q.push(temp);
	}
	for (int i = 0; i < M; ++i) {
		temp = q.front();
		q.pop();
		if (s.find(temp) != s.end()) {
			ret.push(1);
		} else {
			ret.push(0);
		}
	}
	while (!ret.empty()) {
		cout << ret.front() << "\n";
		ret.pop();
	}
	return 0;
}