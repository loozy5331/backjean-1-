#include <iostream>
#include <cstring>
using namespace std;

int cache[1001];

int KindOfN(int w) {
	if (w == 0) return 1;
	if (w < 0) return 0;
	int& ret = cache[w];
	if (ret != -1) return ret;
	return ret = (KindOfN(w - 1)%10007 + KindOfN(w - 2) % 10007) % 10007;
}

int main()
{
	int w;
	memset(cache, -1, sizeof(cache));
	cin >> w;
	cout << KindOfN(w);
	return 0;
}