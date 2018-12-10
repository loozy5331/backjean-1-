#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<long long> nums(N+1);
	vector<long long> cache(N+1, 0);
	for (int i = 0; i < N; ++i)
		cin >> nums[i];
	
	long long MAXNUM = cache[0] = nums[0];
	for (int i = 1; i < N; ++i) {
		long long temp = cache[i - 1] + nums[i]; // ���ݱ����� �ִ븦 �������� ����
		cache[i] = max(temp, nums[i]); // �������� �ʾ��� ��,
		MAXNUM = max(MAXNUM, cache[i]); // ��ü �ִ밪
	}
	cout << MAXNUM << '\n';
}