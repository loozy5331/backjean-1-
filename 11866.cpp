#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int N, M, cnt = 1;
	queue<int> q;
	vector<int> ret;
	scanf("%d %d", &N, &M);
	// √ ±‚»≠
	for (int i = 1; i < N + 1; ++i)
		q.push(i);

	while (!q.empty()) {
		if (cnt == M) {
			ret.push_back(q.front());
			q.pop();
			cnt = 1;
			continue;
		}
		int temp = q.front();
		q.pop();
		q.push(temp);
		cnt++;
	}

	printf("<");
	for (int i = 0; i < ret.size(); ++i)
	{
		printf("%d", ret[i]);
		if (i != ret.size() - 1)
		{
			printf(", ");
		}
	}
	printf(">");
	
	return 0;
}