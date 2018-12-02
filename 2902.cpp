#include <iostream>
#include <string>
using namespace std;

char ret[101];

int main() {
	string temp;
	int cnt = 0;
	cin >> temp;
	for (int i = 0; i < temp.size(); ++i) {
		if ('A' <= temp[i] && temp[i] <= 'Z') {
			ret[cnt++] = temp[i];
		}
		if (i == temp.size() - 1) ret[cnt] = 'a';
	}
	for (int i = 0; i < 101; ++i) {
		if (ret[i] != 'a')
			cout << ret[i];
		else
			break;
	}
}