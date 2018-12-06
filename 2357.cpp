#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;

const int INF = 1e9 + 1;

int max_init(vector<int>& nums, vector<int>& tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = nums[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = max(max_init(nums, tree, node * 2, start, mid),
						max_init(nums, tree, node * 2 + 1, mid + 1, end));
}

int min_init(vector<int>& nums, vector<int>& tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = nums[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = min(min_init(nums, tree, node * 2, start, mid),
		min_init(nums, tree, node * 2 + 1, mid + 1, end));
}

int search_max(vector<int>& tree, int node, int start, int end, int left, int right) {
	if (right < start || end < left) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return max(search_max(tree, node * 2, start, mid, left, right),
		search_max(tree, node * 2 + 1, mid + 1, end, left, right));
}

int search_min(vector<int>& tree, int node, int start, int end, int left, int right) {
	if (right < start || end < left) return INF;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return min(search_min(tree, node * 2, start, mid, left, right),
		search_min(tree, node * 2 + 1, mid + 1, end, left, right));
}


int main() {
	int N, M;
	cin >> N >> M;
	vector<int> nums(N + 1);
	int h = (int)ceil(log2(N));
	int tree_size = (1 << h + 1);
	vector<int> min_tree(tree_size);
	vector<int> max_tree(tree_size);
	vector<pair<int, int>> ret;
	for (int i = 1; i <= N; ++i) {
		cin >> nums[i];
	}
	max_init(nums, max_tree, 1, 1, N);
	min_init(nums, min_tree, 1, 1, N);

	for (int i = 0; i < M; ++i){
		int left, right;
		cin >> left >> right;
		ret.push_back(make_pair(search_min(min_tree, 1, 1, N, left, right), 
								search_max(max_tree, 1, 1, N, left, right)));
	}
	for (int i = 0; i < M; ++i) {
		cout << ret[i].first << " " << ret[i].second << '\n';
	}
}