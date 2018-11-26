#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int findMax(queue<int> pages)
{
	int max = 0;
	while (!pages.empty()) {
		if (pages.front() > max) {
			max = pages.front();
		}
		pages.pop();
	}
	return max;
}

int main()
{
	vector<int> ret;
	int caseN;
	vector<queue<int>> pageNums; // �켱����
	vector<queue<int>> index; // �ε��� ��.
	vector<int> findindex; // ã�ƾ� �ϴ� ���� index
	cin >> caseN;
	pageNums.resize(caseN);
	index.resize(caseN);
	for (int i = 0; i < caseN; ++i) {
		int N, M; // N: ������ ��, M: ���� �������� �˰��� �ϴ� ���� ��ġ
		cin >> N >> M;
		findindex.push_back(M);
		for (int j = 0; j < N; j++) {
			int prior;
			cin >> prior;
			index[i].push(j);
			pageNums[i].push(prior);
		}
	}

	for (int i = 0; i < caseN; ++i) {
		int cnt = 1;
		while (true) {
			int maxPrior = findMax(pageNums[i]);
			int idx = index[i].front();
			index[i].pop();
			int pri = pageNums[i].front();
			pageNums[i].pop();
			int val = findindex[i];
			if (pri != maxPrior) {
				index[i].push(idx);
				pageNums[i].push(pri);
			}
			else {
				if (val == idx) break;
				cnt++;
			}
		}
		ret.push_back(cnt);
	}

	for (int i = 0; i < ret.size(); ++i)
		cout << ret[i] << endl;


	return 0;
}