#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

bool check(string& str) {
	stack<char> space;
	space.push(str[0]);
	for (int i = 1; i < str.size(); ++i) {
		if (str[i] == '(') {
			space.push('(');
		}
		else if (str[i] == '[') {
			space.push('[');
		}
		else if (space.empty()) {
			return false;
		}
		else {
			if (str[i] == ')' && space.top() == '(') {
				space.pop();
				continue;
			}
			else if (str[i] == ']' && space.top() == '[') {
				space.pop();
				continue;
			}
			return false;
		}
	}
	if (!space.empty()) {
		return false;
	}
	return true;
}

int main()
{
	int temp = 1;
	stack<int> Numstack;
	string str;
	cin >> str;
	// 유효한 입력인지 확인.
	if (!check(str)) {
		cout << 0;
		return 0;
	}
	// 처음을 넣음.
	if (str[0] == '(') {
		Numstack.push(-2);
	}
	else if (str[0] == '[') {
		Numstack.push(-3);
	}

	for (int i = 1; i < str.size(); ++i)
	{	
		// 여는 괄호
		// 현재 temp 값에 무언가 의미있는 값이 없을 때,
		if (str[i] == '(' && temp==1) {
			Numstack.push(-2);
		}
		else if (str[i] == '[' && temp == 1) {
			Numstack.push(-3);
		}
		// 현재 temp 값에 무언가 의미있는 값일 때,
		if (str[i] == '(' && temp != 1) {
			Numstack.push(temp);
			temp = 1;
			Numstack.push(-2);
		}
		else if (str[i] == '[' && temp != 1) {
			Numstack.push(temp);
			temp = 1;
			Numstack.push(-3);
		}
		
		
		// 닫는 괄호
		if (str[i] == ')' && Numstack.top() < 0) {
			temp *= (-1 * Numstack.top());
			Numstack.pop();
			while (!Numstack.empty() && Numstack.top() > 0) {
				temp += Numstack.top();
				Numstack.pop();
			}
		}
		else if (str[i] == ']' && Numstack.top() < 0) {
			temp *= (-1 * Numstack.top());
			Numstack.pop();
			while (!Numstack.empty() && Numstack.top() > 0) {
				temp += Numstack.top();
				Numstack.pop();
			}
		}
		
	}
	cout << temp;
	return 0;
}