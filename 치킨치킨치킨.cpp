#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, kind;
int chicken[32][32];
int cache[32][32][32][32];

// n: ¸â¹ö, k: Á¾·ù
int satisfy(int n, int a, int b, int c) {
	if (n == N) return 0;
	int& ret = cache[n][a][b][c];
	if (ret != -1) return ret;
	int maxS = 0;
	maxS = max(maxS, chicken[n][a] + satisfy(n + 1, a, b, c));
	maxS = max(maxS, chicken[n][b] + satisfy(n + 1, a, b, c));
	maxS = max(maxS, chicken[n][c] + satisfy(n + 1, a, b, c));
	return ret = maxS;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N >> kind;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < kind; ++j) {
			cin >> chicken[i][j];
		}
	}
	int result = 0;
	for (int i = 0; i < kind; ++i) {
		for (int j = i + 1; j < kind; ++j) {
			for (int k = j + 1; k < kind; ++k) {
				if (satisfy(0, i, j, k) > result)
					result = satisfy(0, i, j, k);
			}
		}
	}
	cout << result;
	return 0;
}