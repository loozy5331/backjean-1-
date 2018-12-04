#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll sum(vector<ll>& tree, int i) {
	long long sumNum = 0;
	while (i > 0) {
		sumNum += tree[i];
		i -= (i & -i);
	}
	return sumNum;
}

void update(vector<ll>& tree, int i, ll diff) {
	while (i < tree.size()) {
		tree[i] += diff;
		i += (i & -i);
	}
}

int main() {
	cin.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	vector<ll> nums(N + 1);
	vector<ll> tree(N + 1);
	vector<ll> ret;
	for (int i = 1; i <= N; ++i) {
		cin >> nums[i];
		update(tree, i, nums[i]);
	}
	M += K;
	while (M--) {
		ll temp1; cin >> temp1;
		if (temp1 == 1) {
			ll temp2, temp3;
			cin >> temp2 >> temp3;
			ll diff = temp3 - nums[temp2];
			nums[temp2] = temp3;
			update(tree, temp2, diff);
		}
		else {
			ll temp2, temp3;
			cin >> temp2 >> temp3;
			ret.push_back(sum(tree, temp3) - sum(tree, temp2 - 1));
		}
	}

	for (int i = 0; i < ret.size(); ++i) {
		cout << ret[i] << '\n';
	}
}