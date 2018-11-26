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
			field[i][j] = 1000; // �ߺ����� ���� �ʱ� ���ؼ�
	return true;
}

// ������, ��ǥ��, �ʺ�
int paper(int y, int x, int target, int n) {
	if (checkfield(y, x, target, n)) return 1;
	if (n == 1 && field[y][x] != target) return 0; // �ּ� n=1�� �� ���� ���� �� �ֵ���!
	int count = 0, width = n/3;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			// �������� �̵���!!
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