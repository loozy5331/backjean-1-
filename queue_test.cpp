#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n, input, temp;
	queue<int> qlist;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		qlist.push(input);
	}

	for (int i = 1; i <= n; i++) {
		temp = qlist.front();
		qlist.pop();
		cout << i << "번째 입력은 " << temp << "입니다." << endl;
	}

	return 0;
}