#include <iostream>
#include <deque>
using namespace std;

deque<int> dq;
//입력값의 2^n 중에 n을 찾아줌.
int checkPower(int n)
{
	int temp = 0;
	while (n > 1) {
		n /= 2;
		temp++;
	}
	return temp;
}

int main()
{
	int N, jimin, hansu, stage;
	bool flag = false;
	cin >> N >> jimin >> hansu;
	// 초기화
	for (int i = 1; i <= N; ++i)
		dq.push_back(i);
	int power = checkPower(N) + 1;

	for (int i = 1; i <= power; ++i){
		int size = dq.size(), count = 0;
		// 짝수일 때,
		if (size % 2 == 0) {
			for (int j = 0; j < size/2; ++j) {
				count++;
				int num1 = dq.front();
				dq.pop_front();
				int num2 = dq.front();
				dq.pop_front();
				// 중간에 시합하는 경우의 수
				if ((num1 == jimin && num2 == hansu) || (num2 == jimin && num1 == hansu)) {
					flag = true;
					break;
				} else {
					if (num1 == jimin) {
						jimin = count;
					} else if (num1 == hansu) {
						hansu = count;
					}
					if (num2 == jimin) {
						jimin = count;
					} else if (num2 == hansu) {
						hansu = count;
					}
					dq.push_back(count);
				}
				
			}
		}
		//홀수일 때,
		else {
			for (int j = 0; j < size / 2; ++j){
				count++;
				int num1 = dq.front();
				dq.pop_front();
				int num2 = dq.front();
				dq.pop_front();
				// 시합하는 경우의 수
				if ((num1 == jimin && num2 == hansu) || (num2 == jimin && num1 == hansu)) {
					flag = true;
					break;
				}
				else {
					if (num1 == jimin) {
						jimin = count;
					}
					else if (num1 == hansu) {
						hansu = count;
					}
					if (num2 == jimin) {
						jimin = count;
					}
					else if (num2 == hansu) {
						hansu = count;
					}
					dq.push_back(count);
				}
			}
			// 남은 한 사람은 위로 올려줌.
			int num = dq.front();
			dq.pop_front();
			if (num == hansu) {
				hansu = count + 1;
			}else if(num == jimin){
				jimin = count + 1;
			}
			dq.push_back(count + 1);
		}
		stage = i;
		if (flag) break;
	}
	cout << stage;

	return 0;
}