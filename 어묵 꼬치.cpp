#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(int argc, char** argv)
{
	
	int T, test_case;
	cin >> T;
	int *ret = new int[T];
	int cnt = 0;
	for (test_case = 0; test_case < T; test_case++)
	{
		int field[100][100] = { 0 };
		int N;
		cin >> N;
		for (int kochi = 0; kochi < N; ++kochi)
		{
			int x, y, w, h;
			cin >> x >> y >> w >> h;
			for(int i=x; i< x + w; ++i)
				for (int j = y; j < y + h; ++j)
				{
					field[i][j]++;
				}
		}
		int MaxNum = 0;
		for (int i = 0; i < 100; ++i)
			for (int j = 0; j < 100; ++j)
				if (field[i][j] > MaxNum)
					MaxNum = field[i][j];
			
		ret[cnt++] = MaxNum;
	}
	for (int i = 0; i < T; ++i) {
		cout << ret[i] << endl;
	}

	delete[] ret;
	
	return 0;
}