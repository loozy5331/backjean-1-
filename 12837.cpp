#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

void update(vector<ll>& tree, int i, ll diff) {
	while (i < tree.size()) {
		tree[i] += diff;
		i += (i & -i);
	}
}

ll sum(vector<ll>& tree, int i) {
	ll sumNum = 0;
	while (i > 0) {
		sumNum += tree[i];
		i -= (i & -i);
	}
	return sumNum;
}

int main() {
	cin.tie(NULL);
	int N, Q;
	cin >> N >> Q;
	vector<ll> tree(N + 1);
	vector<ll> ret;
	while (Q--) {
		int flag; cin >> flag;
		if (flag == 1) {
			int p;
			ll x;
			cin >> p >> x;
			update(tree, p, x);
		}
		else {
			int p, q;
			cin >> p >> q;
			ret.push_back(sum(tree, q) - sum(tree, p-1));
		}
	}
	for (int i = 0; i < ret.size(); ++i) {
		cout << ret[i] << '\n';
	}

}