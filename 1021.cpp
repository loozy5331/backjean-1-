#include <iostream>
#include <queue>
#include <deque>
using namespace std;

deque<int> dq; // 현재 저장되어 있는 숫자들 + 현재 상태
queue<int> q; // 찾아야 하는 리스트

int findIndex(deque<int> dq, int n)
{
	int idx = 0;
	int temp = dq.front();
	while (temp != n) {
		dq.pop_front();
		temp = dq.front();
		idx++;
	}
	return idx;
}

int RotateQ(deque<int>& dq, queue<int>& q)
{
	int count = 0;
	int tempq, tempdq, index;
	while (true){
		tempq = q.front();
		q.pop();
		tempdq = dq.front();
		if (tempdq == tempq) {
			if (q.empty()) 
				break;
			else { 
				dq.pop_front(); 
				continue; 
			}
		}
		else {
			index = findIndex(dq, tempq);
			if (index <= (dq.size() / 2)) {
				while(tempq != tempdq) {
					dq.pop_front();
					dq.push_back(tempdq);
					count++;
					tempdq = dq.front();
				}
				dq.pop_front();
				if (q.empty()) break;
				else continue;
			}
			else {
				while(tempq != tempdq) {
					tempdq = dq.back();
					dq.pop_back();
					dq.push_front(tempdq);
					count++;
				}
				dq.pop_front();
				if (q.empty()) break;
				else continue;
			}
		}
	}
	return count;
}

int main()
{
	int N, M;
	cin >> N >> M;
	// 초기화
	for (int i = 1; i < N + 1; ++i)
		dq.push_back(i);
	
	for (int i = 0; i < M; ++i) {
		int temp;
		cin >> temp;
		q.push(temp);
	}
	cout << RotateQ(dq, q);
	return 0;
}