#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, K;
vector<int> moneys;

int minimum(vector<int>& v) {
	int mini = moneys[v[0]];
	for(int i = 1; i < v.size(); ++i) {
		if (moneys[v[i]] < mini)
			mini = moneys[v[i]];
	}
	return mini;
}

class Graph {
public:
	int N;
	vector<vector<int>> adj;
	vector<bool> visited;

	Graph():N(0){}
	Graph(int n)
		: N(n) {
		adj.resize(N);
		visited.resize(N);
	}
	void addEdge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int dfsAll() {
		int minimunCost = 0;
		fill(visited.begin(), visited.end(), false);
		for (int i = 0; i < N; ++i) {
			vector<int> temp;
			if (!visited[i]) {
				dfs(i, temp);
				minimunCost += minimum(temp);
			}
		}
		return minimunCost;
	}

private:
	void dfs(int curr, vector<int>& temp) {
		visited[curr] = true;
		temp.push_back(curr);
		for (int next : adj[curr]) {
			if (!visited[next]) dfs(next, temp);
		}
	}
};

int main() {
	cin >> N >> M >> K;
	moneys.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> moneys[i];
	Graph g(N);
	for (int i = 0; i < M; ++i) {
		int tempu, tempv;
		cin >> tempu >> tempv;
		g.addEdge(tempu-1, tempv-1);
	}
	if (g.dfsAll() > K) cout << "Oh no";
	else cout << g.dfsAll();

}