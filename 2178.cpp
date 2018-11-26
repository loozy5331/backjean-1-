#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int N, M;
int INF = 987654321;
string maze[101];
int flag[101][101];
queue<pair<int, int>> q;
// 좌우 상하
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int findDistance(int y, int x) {
	// 초기 조건.
	q.push(make_pair(y, x));
	while (!q.empty()) {
		pair<int, int> temp = q.front(); q.pop();
		int nY, nX, minD = INF;
		for (int i = 0; i < 4; ++i) {
			nY = temp.first + dy[i]; nX = temp.second + dx[i];
			if (nY >= 0 && nY < N && nX >= 0 && nX < M && maze[nY][nX] == '1' && flag[nY][nX] == INF) {
				q.push(make_pair(nY, nX));
				flag[nY][nX] = flag[temp.first][temp.second] + 1;
			}
		}
	}
	return flag[N-1][M-1];
}


int main()
{
	string temp;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			flag[i][j] = INF;
		}
	}
	for (int i = 0; i < N; ++i)
		cin >> maze[i];
	flag[0][0] = 1;
	cout << findDistance(0, 0);
	return 0;
}