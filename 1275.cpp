#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

ll init(vector<ll>& nums, vector<ll>& tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = nums[start];
	}
	else {
		int mid = (start + end) / 2;
		return tree[node] = init(nums, tree, node * 2, start, mid)
			+ init(nums, tree, node * 2 + 1, mid + 1, end);
	}
}

ll sum(vector<ll>& tree, int node, int start, int end, int left, int right) {
	if (right < start || end < left) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return sum(tree, node * 2, start, mid, left, right)
		+ sum(tree, node * 2 + 1, mid + 1, end, left, right);
}

void update(vector<ll>& tree, int node, int index, int start, int end, ll diff) {
	if (index < start || end < index) return;
	tree[node] += diff;
	if (start != end) {
		int mid = (start + end) / 2;
		update(tree, node * 2, index, start, mid, diff);
		update(tree, node * 2 + 1, index, mid + 1, end, diff);
	}
}

int main() {
	int N, Q;
	cin >> N >> Q;
	vector<ll> nums(N + 1);
	int h = (int)ceil(log2(N));
	vector<ll> tree(1 << h + 1);
	vector<ll> ret;
	for (int i = 1; i <= N; ++i) {
		cin >> nums[i];
	}
	init(nums, tree, 1, 1, N);
	for (int i = 0; i < Q; ++i) {
		ll x, y, a, b;
		cin >> x >> y >> a >> b;
		if (x > y) {
			ret.push_back(sum(tree, 1, 1, N, y, x));
		}
		else {
			ret.push_back(sum(tree, 1, 1, N, x, y));
		}
		ll diff = b - nums[a];
		update(tree, 1, a, 1, N, diff);
		nums[a] = b;
	}
	for (int i = 0; i < Q; ++i) {
		cout << ret[i] << '\n';
 	}
}