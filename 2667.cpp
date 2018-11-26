#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

vector<string> v;
vector<int> ret;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int deleteOne(int, int);

void dangi(vector<string>& v) {
	for (int row = 0; row < v.size(); ++row) {
		for (int col = 0; col < v[0].size(); ++col) {
			if (v[row][col] == '1') {
				ret.push_back(deleteOne(row, col));
			}
		}
	}
}

int deleteOne(int y, int x) {
	int count = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();
		v[temp.first][temp.second] = '0';
		for (int i = 0; i < 4; ++i) {
			int ny = temp.first + dy[i];
			int nx = temp.second + dx[i];
			if (ny >= 0 && ny < v.size() && nx >= 0 && nx < v[0].size() && v[ny][nx] == '1'){
				q.push(make_pair(ny, nx));
				v[ny][nx] = '0';
			}
		}
		count++;
	}
	return count;
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string temp;
		cin >> temp;
		v.push_back(temp);
	}
	dangi(v);
	cout << ret.size() << "\n";
	sort(ret.begin(), ret.end());
	for (int i = 0; i < ret.size(); ++i) {
		cout << ret[i] << "\n";
	}
	return 0;
}