#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> add(string& A, string& B) {
	if (B.size() > A.size()) {
		return add(B, A);
	}

	stack<char> result;
	stack<char> As;
	stack<char> Bs;
	for (int i = 0; i < A.size(); ++i) {
		As.push(A[i]);
	}
	for (int i = 0; i < B.size(); ++i) {
		Bs.push(B[i]);
	}
	
	int carry = 0;
	for (int i = 0; i < A.size(); ++i) {
		if (!Bs.empty()) {
			int temp = (As.top() - '0') + (Bs.top() - '0') + carry;
			if (temp >= 10) {
				temp -= 10;
				carry = 1;
			}
			else {
				carry = 0;
			}
			result.push(temp + '0');
			As.pop(); Bs.pop();
		}
		else {
			int temp = As.top() - '0' + carry;
			if (temp >= 10) {
				temp -= 10;
				carry = 1;
			}
			else {
				carry = 0;
			}
			result.push(temp + '0');
			As.pop();
		}
	}
	if (carry == 1) {
		result.push('1');
	}

	return result;
}

int main() {
	string A, B;
	cin >> A >> B;
	stack<char> ret = add(A, B);
	while (!ret.empty()) {
		cout << ret.top();
		ret.pop();
	}
}