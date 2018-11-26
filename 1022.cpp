#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

long long field[50][50] = { 0 };

int maxNum(long long arr[][50], int row, int column)
{
	int max = arr[0][0];
	for(int i=0;i<row;i++)
		for (int j = 0; j < column; j++)
			if (max < arr[i][j]) max = arr[i][j];
		
	return max;
}

int main()
{
	int axis[4]; // 입력값
	for (int i = 0; i < 4; i++) 
		scanf("%d", &axis[i]);
	int r1 = axis[0], c1 = axis[1], r2 = axis[2], c2 = axis[3];
	int row = r2 - r1, column = c2 - c1;
	int maxlen = max(row, column);
	int x = -r1, y = -c1; // 시작좌표(0,0)
	vector<long long> directionNum; // {1, 1, 2, 2, 3, 3, 4, 4 ... ,maxlen, maxlen} len: maxlen*2
	for (int i = 1; i < maxlen*2; i++)
		for (int j = 0; j < 2; j++)
			directionNum.push_back(i);
	
	int cnt = 1; // 입력되는 값
	int count = 0;
	bool exitflag = false; // 탈출 조건
	bool signflag = true; // 부호 조건
	bool directionflag = true; // 방향 조건
	while (!exitflag) {
		if (signflag == true && directionflag == true) {	// 오른쪽
			for (int i = 0; i < directionNum[count]; i++) {
				if (field[x][y] == 0) {
					field[x][y] = cnt++;
					y += 1;
					signflag = false;
					directionflag = false;
				}
				else {
					cnt++;
				}
			}
			count++;
		}
		else if (signflag == false && directionflag == false){	// 위
			for (int i = 0; i < directionNum[count]; i++) {
				if (field[x][y] == 0) {
					field[x][y] = cnt++;
					x -= 1;
					directionflag = true;
				}
				else {
					cnt++;
				}
			}
			count++;
		}
		else if (signflag == false && directionflag == true) {	// 왼쪽
			for (int i = 0; i < directionNum[count]; i++) {
				if (field[x][y] == 0) {
					field[x][y] = cnt++;
					y -= 1;
					signflag = true;
					directionflag = false;
				}
				else {
					cnt++;
				}
			}
			count++;
		}
		else if (signflag == true && directionflag == false)	{	// 아래
			for (int i = 0; i < directionNum[count]; i++) {
				if (field[x][y] == 0) {
					field[x][y] = cnt++;
					x += 1;
					directionflag = true;
				}
				else {
					cnt++;
				}
			}
			count++;
			continue;
		}

		// 종료조건
		if (field[0][0] != 0 && field[row][column] != 0 &&
			field[0][column] != 0 && field[row][0] != 0) {
			exitflag = true;
		}
	}
	long long maxNumint = maxNum(field, row, column);
	string maxNumstr = to_string(maxNumint);
	int len = maxNumstr.length();
	for (int i = 0; i < row+1; i++)
	{
		for (int j = 0; j < column+1; j++)
		{
			string numstr = to_string(field[i][j]);
			int numlen = numstr.length();
			for (int l = 0; l < (len - numlen); l++)
				printf(" ");
			printf("%lld ", field[i][j]);
		}
		printf("\n");
	}
	return 0;
}