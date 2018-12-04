#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll sum(vector<ll>& tree, int i) {
	ll sumNum = 0;
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
	int N, M;
	cin >> N >> M;
	vector<ll> nums(N + 1);
	vector<ll> tree(N + 1);
	vector<ll> ret;
	while (M--) {
		int flag; cin >> flag;
		ll temp1, temp2;
		cin >> temp1 >> temp2;
		if (flag == 0) {
			if (temp1 > temp2) swap(temp1, temp2);
			ret.push_back(sum(tree, temp2) - sum(tree, temp1-1));
		}
		else {
			ll diff = temp2 - nums[temp1];
			update(tree, temp1, diff);
			nums[temp1] = temp2;
		}
	}
	for (auto i : ret) {
		cout << i << '\n';
	}
	
}