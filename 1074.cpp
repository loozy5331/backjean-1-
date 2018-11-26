#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int N, R, C;
int total = 0;

// 시작점, 지수
int Z_search(int y, int x, int n) {
	if (y == R && x == C) return total;
	bool flag = false;
	int nextN = n-1;
	int pivot = pow(2, n-1);

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			if (R < y + pivot * (i + 1) && C < x + pivot * (j + 1)) {
				// 딱히 반환 안해도 선언은 가능!
				Z_search(y + pivot * i, x + pivot * j, nextN);
				flag = true;
				break;
			}
			total += pow(pivot, 2);
		}
		if (flag) break;
	}
	// 딱히 반환하는 것이 없음ㅋㅋ 뭘까 이건
	return total;
}

int main() {
	cin >> N >> R >> C;
	cout << Z_search(0, 0, N);
}