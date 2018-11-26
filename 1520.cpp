#include <iostream>
#include <cstring>
using namespace std;

int M, N;
int field[501][501];
int cache[501][501];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { -1, 1, 0, 0 };

int downStair(int y, int x) {
	// 기저사건
	if (y == M-1 && x == N-1) return 1;
	int& ret = cache[y][x];
	if (ret != -1) return ret;
	int Count = 0;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny < M && nx >= 0 && nx < N
			&& field[ny][nx] < field[y][x] ) {
			Count += downStair(ny, nx);
		}
	}
	return ret = Count;
 }


int main()
{
	cin >> M >> N;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> field[i][j];
		}
	}
	cout << downStair(0, 0);

	return 0;
}