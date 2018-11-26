#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

void clear(stack<int>& s)
{
	while (!s.empty())
		s.pop();
}

int sumOfStack(stack<int> s)
{
	int sumN = 0;
	while (!s.empty()) {
		sumN += s.top();
		s.pop();
	}
	return sumN;
}


int main()
{
	int X, len = 64;
	cin >> X;
	s.push(len);
	while (sumOfStack(s) != X){
		int temp = s.top();
		s.pop();
		// 막대 하나가 더 클 때,
		if (temp > X) {
			clear(s);
			s.push(temp / 2);
		}
		else {
			s.push(temp);
			if (sumOfStack(s) <= X)
				s.push(temp / 2);
			else {
				s.pop();
				s.push(temp / 2);
			}
		}
	}
	cout << s.size();
	return 0;
}