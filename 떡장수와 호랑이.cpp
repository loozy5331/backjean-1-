#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N;
// n��, ���� ���� ���� ������ ���� �� -1�� �ʱ�ȭ
int dduck[1001][10];
vector<int> v;

void life(int day, int k, vector<int>& v) {
	if (day == N) return;
	for (int i = 0; i < 10; ++i) {
		// ������ dduck�� ���� -1�̸� �� ��¥���� ��
		if (dduck[day][i] == -1) break;
		if (day == 0 || dduck[day][k] != dduck[day][i]) {
			v.push_back(dduck[day][i]);
			life(day + 1, i, v);
		}
		v.pop_back();
	}
}

int main()
{
	memset(dduck, -1, sizeof(dduck));
	int temp1, temp2;
	cin >> N;
	for (int day = 0; day < N; ++day) {
		cin >> temp1;
		for (int d = 0; d < temp1; ++d) {
			cin >> temp2;
			dduck[day][d] = temp2;
		}
	}
	life(0, 0, v);
	cout << "hello";


	return 0;
}