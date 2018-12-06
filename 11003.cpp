#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int INF = 5000001;

int init(vector<int>& nums, vector<int>& tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = nums[start];
	}
	else {
		return tree[node] = min(init(nums, tree, 2 * node, start, (start + end) / 2),
			init(nums, tree, 2 * node + 1, (start + end) / 2 + 1, end));
	}
}

int minNum(vector<int>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return INF;
	}
	if(left <= start && end <= right) { 
		return tree[node];
	}
	return min(minNum(tree, 2 * node, start, (start + end) / 2, left, right),
		minNum(tree, 2 * node + 1, (start + end) / 2 + 1, end, left, right));
}

int main() {
	int N, L;
	scanf("%d %d", &N, &L);
	vector<int> nums(N + 1);
	int h = (int)ceil(log2(N));
	int tree_size = (1 << h + 1);
	vector<int> tree(tree_size);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &nums[i]);
	}
	init(nums, tree, 1, 1, N);
	for (int right = 1; right <= N; ++right) {
		if (right - L + 1 <= 0) {
			printf("%d", minNum(tree, 1, 1, N, 1, right));
		}
		else {
			printf("%d", minNum(tree, 1, 1, N, right-L+1, right));
		}
		if (right != N) printf(" ");
	}
}