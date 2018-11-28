#include <iostream>
#include <cstring>
using namespace std;

int N;
char build[3072][3072 * 2];
void star(int y, int x, int n) {
	if (n == 3) {
		build[y][x] = '*';
		build[y + 1][x - 1] = '*';
		build[y + 1][x + 1] = '*';
		for (int i = -2; i < 3; ++i)
			build[y + 2][x + i] = '*';
	}
	else {
		star(y, x, n / 2);
		star(y + n / 2, x - n / 2, n / 2);
		star(y + n / 2, x + n / 2, n / 2);
	}
}

int main() {
	cin >> N;
	memset(build, ' ', sizeof(build));
	star(0, N-1, N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 2*N; ++j) {
			cout << build[i][j];
		}
		cout << endl;
	}
}