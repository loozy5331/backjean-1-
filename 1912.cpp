#include <iostream>
using namespace std;

const int MINNUM = -1e7;
int N;
int cost[100001];
int cache[100001];

int main() {
	int result = 0;
	cin >> N;
	for (int i = 0; i < N; ++i) 
		cin >> cost[i];
	fill(cache, cache + 100001, MINNUM);

	cache[0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = i; j < N; ++j) {
		if (cache[j] < cache[j] + cost[j])
				cache[j] = cache[j] + cost[j];
		}
	}
	for (int i = 0; i < N; ++i) {
		if (cache[i] > result)
			result = cache[i];
	}
	cout << result;
}