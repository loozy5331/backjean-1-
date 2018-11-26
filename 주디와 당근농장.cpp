#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string field[101][101];

int main()
{
	int N, R, C;
	int flag = 1;
	int startC= 1;
	cin >> N >> R >> C;
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j) {
			field[i][j] = ".";
		}
	}
	field[R - 1][C - 1] = "v";
	if ((R - 1) % 2 == 1 && (C-1) % 2 == 1) flag=0;
	if ((R - 1) % 2 == 0 && (C - 1) % 2 == 1) flag = 1;
	if ((R - 1) % 2 == 1 && (C - 1) % 2 == 0) flag = 1;
	if ((R - 1) % 2 == 0 && (C - 1) % 2 == 0) flag = 0;


	for (int i = 0; i < N; ++i) {
		for (int j = flag; j < N; j += 2) {
			field[i][j] = "v";
		}
		if (flag == 0) flag = 1;
		else if (flag == 1) flag = 0;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << field[i][j];
		}
		cout << endl;
	}
	return 0;
}