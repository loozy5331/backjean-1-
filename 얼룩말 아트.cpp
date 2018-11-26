#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

int H, W, N;
string canvas[2501];
int field[2501][2501] = {0, };

void drawsqaure(int px, int py, int qx, int qy) {
	for (int i = py; i < qy+1; ++i) {
		for (int j = px; j < qx+1; ++j) {
			field[i][j]++;
		}
	}
}

void drawdia(int px, int py, int r) {
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (abs(j - px) + abs(i - py) <= r) {
				field[i][j]++;
			}
		}
	}
}


int main()
{
	cin.tie(NULL);
	cin >> W >> H >> N;

	string temp = "";
	for (int j = 0; j < W; ++j) {
		temp += '.';
	}
	for (int i = 0; i < H; ++i) {
		canvas[i] = temp;
	}

	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		if (temp == 1) {
			int px, py, qx, qy;
			cin >> px >> py >> qx >> qy;
			drawsqaure(px, py, qx, qy);
		}
		else {
			int px, py, r;
			cin >> px >> py >> r;
			drawdia(px, py, r);
		}
	}

	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (field[i][j] % 2 == 0) {
				canvas[i][j] = '.';
			}
			else {
				canvas[i][j] = '#';
			}
		}
	}
	for (int i = 0; i < H; ++i) {
		cout << canvas[i] << endl;
	}
	return 0;
}