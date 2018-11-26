#include <iostream>
#include <string>
using namespace std;

int N;
int field[65][65];
bool visited[65][65] = {false, };

// 하나의 숫자로 되어있는지 확인.
bool checkfield(int y, int x, int n){
	int target = field[y][x];
	for (int i = y; i < y + n; ++i) 
		for (int j = x; j < x + n; ++j) 
			if (field[i][j] != target) return false;
		
	for (int i = y; i < y + n; ++i) 
		for (int j = x; j < x + n; ++j) 
			visited[i][j] = true;
		
	return true;
}

// 시작점, 너비
string QuardTree(int y, int x, int n) {
	string result = "(";
	if (checkfield(y, x, n)) return to_string(field[y][x]);
	if (n == 1 && !visited[y][x]) { 
		visited[y][x] = true;  
		return to_string(field[y][x]); 
	}
	if (n == 1 && visited[y][x]) return "";
	int width = n / 2;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			result += QuardTree(i*width + y, j*width + x, width);
		}
	}
	return result + ")";
}

int main(){
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.size(); ++j) {
			field[i][j] = temp[j] - '0';
		}
	}
	cout << QuardTree(0, 0, N);
}