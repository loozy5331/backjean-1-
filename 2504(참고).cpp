#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Stack {
	int list[100] = { 0 };
	int top = -1;
	int tmp = 1;
public:
	bool ex = true;
	void error() {
		ex = false;
	}
	void print() {
		cout << list[0];
	}
	void reset() {
		top = -1;
		ex = true;
	}
	int get() {
		return top;
	}
	void Push(int n) {
		if (n > 0 && list[top] > 0)
			list[top] += n;
		else {
			top++; list[top] = n;
		}
	}
	void Pop(char c = '\0') {
		if (top <= -1) { ex = false; return; }
		if (c == ')') {
			for (int index = 0; index < 2; index++) {
				if (list[top] == -3) {//[老版快
					error(); top + index;  tmp = 1; return;//
				}
				else if (list[top] != -2 && index == 0) {	//箭磊老 版快
					tmp *= list[top]; list[top] = 0; top--;
				}
				else if (list[top] == -2) {
					tmp *= 2; list[top] = 0; top--; Push(tmp); tmp = 1; return;
				}
				else if (list[top] != -2 && index == 1) {
					error(); top + index; tmp = 1; return;
				}
			}
		}
		else if (c == ']') {
			for (int index = 0; index < 2; index++) {
				if (list[top] == -2) {//(老版快
					error(); top + index;  tmp = 1; return;//
				}
				else if (list[top] != -3 && index == 0) {	//箭磊老 版快
					tmp *= list[top]; list[top] = 0; top--;
				}
				else if (list[top] == -3) {//[老版快
					tmp *= 3; list[top] = 0; top--; Push(tmp); tmp = 1; return;
				}
				else if (list[top] != -3 && index == 1) {
					error(); top + index; tmp = 1; return;
				}
			}
		}
	}
};

int main() {
	int num = 1;
	Stack s;
	string str;
	//	cin >> num;
	//	cin.ignore();
	//for (int i = 0; i < num; i++) {
	getline(cin, str);
	s.reset();
	for (int index = 0; str[index] != '\0'; index++) {
		if (str[index] == '(') {
			s.Push(-2);
		}
		else if (str[index] == '[')
			s.Push(-3);
		else if (str[index] == ')') {
			s.Pop(')');
		}
		else
			s.Pop(']');
	}
	if (s.get() == 0 && s.ex) s.print();
	else  cout << 0;
	//}
}