#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int N, R, C;
int total = 0;

// ������, ����
int Z_search(int y, int x, int n) {
	if (y == R && x == C) return total;
	bool flag = false;
	int nextN = n-1;
	int pivot = pow(2, n-1);

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			if (R < y + pivot * (i + 1) && C < x + pivot * (j + 1)) {
				// ���� ��ȯ ���ص� ������ ����!
				Z_search(y + pivot * i, x + pivot * j, nextN);
				flag = true;
				break;
			}
			total += pow(pivot, 2);
		}
		if (flag) break;
	}
	// ���� ��ȯ�ϴ� ���� �������� ���� �̰�
	return total;
}

int main() {
	cin >> N >> R >> C;
	cout << Z_search(0, 0, N);
}