#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

void update(vector<ll>& tree, int i, ll val) {
	while (i < tree.size()) {
		tree[i] *= val/1000000007;
		i += (i & -i);
	}
}

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<ll> nums(N + 1);
	vector<ll> tree(N + 1);
	for (int i = 1; i <= N; ++i) {
		tree[i] = 1;
	}
	for (int i = 1; i <= N; ++i) {
		cin >> nums[i];
		update(tree, i, nums[i]);
	}

}