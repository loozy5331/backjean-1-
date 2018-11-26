#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int N, count = 0;
char field[51][51];

// 열 별로 가장 긴 길이.
int checkMaxcol() {
	int len = 0;
	for (int i = 0; i < N; ++i) {
		char tempC = field[i][0];
		int tempL = 0;
		for (int j = 0; j < N; ++j) {
			if (field[i][j] == tempC) {
				tempL++;
			}
			else {
				tempC = field[i][j];
				len = max(len, tempL);
				tempL = 1;
			}
		}
		len = max(len, tempL);
	}
	return len;
}

// 행 별로 가장 긴 길이
int checkMaxrow() {
	int len = 0;
	for (int j = 0; j < N; ++j) {
		char tempC = field[0][j];
		int tempL = 0;
		for (int i = 0; i < N; ++i) {
			if (field[i][j] == tempC) {
				tempL++;
			}
			else {
				tempC = field[i][j];
				len = max(len, tempL);
				tempL = 1;
			}
		}
		len = max(len, tempL);
	}
	return len;
}

int main() {
	int result = 0;
	cin >> N;
	for (int i = 0; i < N; ++i) 
		for (int j = 0; j < N; ++j) 
			cin >> field[i][j];
	
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			int ny = y + 1;
			int nx = x + 1;
			if (ny >= 0 && ny < N) {
				swap(field[y][x], field[ny][x]);
				result = max(result, max(checkMaxcol(), checkMaxrow()));
				swap(field[y][x], field[ny][x]);
			}
			if (nx >= 0 && nx < N) {
				swap(field[y][x], field[y][nx]);
				result = max(result, max(checkMaxcol(), checkMaxrow()));
				swap(field[y][x], field[y][nx]);
			}
		}
	}
	cout << result;
}