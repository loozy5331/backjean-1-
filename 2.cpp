#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int path[12][12][12][12];

int solution(string dirs)
{
	memset(path, -1, sizeof(path));
	int answer = 0;
	int sx = 5, sy = 5;
	int len = dirs.size();
	path[sx][sy][sx][sy] = 0;
	for (int i = 0; i < len; ++i) {
		if (dirs[i] == 'U' && sy + 1 >= 0 && sy + 1 <= 10
			 && path[sx][sy][sx][sy + 1] == -1) {
			 path[sx][sy][sx][sy + 1] = 0; sy += 1;
		}
		if (dirs[i] == 'D' && sy-1 >= 0 && sy-1 <= 10
			&& path[sx][sy][sx][sy - 1] == -1) {
			path[sx][sy][sx][sy-1] = 0; sy -= 1;
		}
		if (dirs[i] == 'L' && sx - 1 >= 0 && sx - 1 <= 10
			&& path[sx][sy][sx-1][sy] == -1) {
			path[sx][sy][sx-1][sy] = 0; sx -= 1;
		}
		if (dirs[i] == 'R' && sx + 1 >= 0 && sx + 1 <= 10
			&& path[sx][sy][sx + 1][sy] == -1) {
			path[sx][sy][sx + 1][sy] = 0; sx += 1;
		}
	}
	for (int i = 0; i < 11; ++i) {
		for (int j = 0; j < 11; ++j) {
			for (int k = 0; k < 11; ++k) {
				for (int a = 0; a < 11; ++a) {
					if (path[i][j][k][a] == 0)
						answer++;
				}
			}
		}
	}
	return answer-1;
}



int main()
{
	string dirs = "LULLLLLLU";
	cout << solution(dirs);
	cout << "hell";
	return 0;
}