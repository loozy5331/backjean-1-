#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int height[52];
vector<pair<int, int>> H_W;
vector<pair<int, int>> H_level;
int level[52];

int search_val(vector<pair<int, int>>& V_pair, int num)
{
	for (int i = 0; i < V_pair.size(); ++i)
		if (V_pair[i].first == num)
			return V_pair[i].second;
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int h, w;
		cin >> h >> w;
		height[i] = h;
		H_W.push_back(make_pair(h, w));
	}
	sort(height, height + N);
	for (int i = 0; i < N; ++i)
	{
		int grade = 1;
		for (int j = i; j < N; ++j)
			if (search_val(H_W, height[i]) < search_val(H_W, height[j]))
				grade++;
		H_level.push_back(make_pair(height[i], grade));
	}

	for(int i=0;i<N;++i)
	{
		if (i != N - 1)
			cout << search_val(H_level, H_W[i].first) << " ";
		else
			cout << search_val(H_level, H_W[i].first);
	}
	
}