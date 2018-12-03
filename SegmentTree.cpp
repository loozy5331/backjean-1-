#include <iostream>
#include <vector>
using namespace std;

vector<int> tree;
vector<int> dataA;

int init(int node, int begin, int end) {
	if (begin == end) return tree[node] = dataA[begin];
	int mid = (begin + end) / 2;
	cout << node << endl;
	return tree[node] = init(node * 2, begin, mid) + init(node * 2 + 1, mid + 1, end);
}

int sum(int node, int begin, int end, int left, int right) {
	if (end < left || right < begin) return 0;
	if (left <= begin && end <= right) return tree[node];
	int mid = (begin + end) / 2;
	return sum(node * 2, begin, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int begin, int end, int index, int diff) {
	if (index < begin || end < index) return;
	tree[node] += diff;
	if (begin == end) return;
	int mid = (begin + end) / 2;
	update(node * 2, begin, mid, index, diff);
	update(node * 2 + 1, mid + 1, end, index, diff);
}

int main() {
	dataA.push_back(3);
	dataA.push_back(4);
	dataA.push_back(3);
	dataA.push_back(4);
	tree.resize(2 * dataA.size());
	cout << init(1, 0, 3);

}