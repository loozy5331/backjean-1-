#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Tree {
public:
	int N;
	vector<int> parent;
	vector<vector<int>> children;

	Tree() : N(0) { }
	Tree(int n) : N(n) {
		parent.resize(N, -1);
		children.resize(N);
	}

	void print() {
		for (int i = 0; i < N; ++i) {
			cout << "Node " << i << ": parent(";
			if (parent[i] != -1) cout << parent[i];
			else cout << "-";
			cout << "), children(";
			for (int j = 0; j < children[i].size(); j++) {
				cout << children[i][j];
				if (j < (children[i].size() - 1)) 
					cout << ", ";
			}
			cout << ")" << endl;
		}
	}
};

class Graph {
public:
	int N;
	vector<vector<int>> adj;

	Graph() : N(0) {}
	Graph(int n) : N(n) { adj.resize(N); }

	void addEdge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void sortList() {
		for (int i = 0; i < N; ++i) {
			sort(adj[i].begin(), adj[i].end());
		}
	}

	Tree makeTree(int root) {
		Tree T(N);
		vector <bool> visited(N, false);
		queue<int> Q;

		visited[root] = true;
		Q.push(root);
		while (!Q.empty()) {
			int curr = Q.front();
			Q.pop();
			for (int next : adj[curr]) {
				if (!visited[next]) {
					visited[next] = true;
					Q.push(next);
					T.parent[next] = curr;
					T.children[curr].push_back(next);
				}
			}
		}
		return T;
	}

};

int main() {
	Graph G(9);
	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(1, 3);
	G.addEdge(1, 5);
	G.addEdge(3, 4);
	G.addEdge(4, 5);
	G.addEdge(2, 6);
	G.addEdge(2, 8);
	G.addEdge(6, 7);
	G.addEdge(6, 8);
	G.sortList();
	Tree T = G.makeTree(0);
	T.print();
}