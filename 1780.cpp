#include <iostream>
#include <algorithm>
using namespace std;

int N;
int field[2188][2188];

bool checkfield(int y, int x, int target, int n){
	for (int i = y; i < y+n; ++i) 
		for (int j = x; j < x+n; ++j) 
			if (field[i][j] != target) return false;
	for (int i = y; i < y + n; ++i)
		for (int j = x; j < x + n; ++j)
			field[i][j] = 1000; // 중복으로 세지 않기 위해서
	return true;
}

// 시작점, 목표값, 너비
int paper(int y, int x, int target, int n) {
	if (checkfield(y, x, target, n)) return 1;
	if (n == 1 && field[y][x] != target) return 0; // 최소 n=1일 때 값을 받을 수 있도록!
	int count = 0, width = n/3;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			// 시작점이 이동함!!
			count += paper(i * width + y, j * width + x, target, width);
		}
	}
	return count;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) 
		for (int j = 0; j < N; ++j) 
			cin >> field[i][j];
	
	cout << paper(0, 0, -1, N) << endl;
	cout << paper(0, 0, 0, N) << endl;
	cout << paper(0, 0, 1, N) << endl;
}