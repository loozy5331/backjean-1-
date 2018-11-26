#include <string>
#include <vector>
#include <iostream>

using namespace std;

int sum(int start, int end, vector<int> a) {
	int len = a.size();
	int Sum = 0;
	for (int i = start; i < end; ++i) {
		Sum += a[i];
	}
	return Sum;
}

int solution(vector<int> cookie) {
	int answer = -1;
	int len = cookie.size();
	
}


int main() {
	vector<int> a = { 1, 1, 2, 3 };
	cout << solution(a);
	return 0;
}