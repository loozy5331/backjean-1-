#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

const ll INF = 1e9 + 1;

ll init(vector<ll>& nums, vector<ll>& tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = nums[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = min(init(nums, tree, node * 2, start, mid),
					init(nums, tree, node * 2 + 1, mid + 1, end));
	
}

ll minNum(vector<ll>& tree, int node, int start, int end, int left, int right) {
	if (right < start || end < left) return INF;
	else if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return min(minNum(tree, node * 2, start, mid, left, right),
			minNum(tree, node * 2 + 1, mid + 1, end, left, right));
}

int main() {
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<ll> nums(N + 1);
	int h = (int)ceil(log2(N));
	int tree_size = (1 << h + 1);
	vector<ll> tree(tree_size);
	vector<ll> ret;
	for (int i = 1; i <= N; ++i)
		cin >> nums[i];
	init(nums, tree, 1, 1, N);
	for (int i = 0; i < M; ++i) {
		int tempA, tempB;
		cin >> tempA >> tempB;
		ret.push_back(minNum(tree, 1, 1, N, tempA, tempB));
	}
	for (int i = 0; i < ret.size(); ++i) {
		cout << ret[i] << '\n';
	}
}