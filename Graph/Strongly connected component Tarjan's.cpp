#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

/*

10/20/2020   1:20 AM (GTM +1)
written by Iyad M. Alazzam
this code's applying Tarjan's algorithm to get
the strongly connected component(SCC->collection of cycles)
to undirected graph.

*/

struct Graph {
	// ids -> if it's equal by -1 then it's unvisited otherwise it's
	int id, SCCSCount, n;
	bool* inStack;
	vector <vector<int>> g, SCCS; // SCCS: you can find all strongly connected components here in this vector.
	stack<int> stk;
	int* low, * ids;

	Graph(int n) { // all sizes increased by 1 for safety reasons.
		Graph::n = n;
		SCCSCount = 0, id = 0;
		g.resize(n + 5);
		inStack = new bool[n + 5];
		low = new int[n + 5];
		ids = new int[n + 5];
	}
	~Graph() {
		delete[] inStack, low, ids;
		low = ids = NULL;
		inStack = NULL;
	}

private:
	void dfs(int at) {

		stk.push(at);
		inStack[at] = 1;
		low[at] = ids[at] = id++;

		for (auto& a : g[at]) {
			if (ids[a] == -1) {
				dfs(a);
			}
			if (inStack[a])low[at] = min(low[a], low[at]);
		}

		vector<int> scc;

		if (ids[at] == low[at]) {
			while (!stk.empty()) {

				int node = stk.top();
				scc.push_back(node);
				stk.pop();

				low[node] = ids[at];
				inStack[node] = false;

				if (node == at)
					break;
			}
			SCCS.push_back(scc);
			SCCSCount++;
		}
	}

public:
	void buildSCCS() {
		for (int i = 0; i < n; i++) {
			ids[i] = -1;
		}
		for (int i = 0; i < n; i++) {
			if (ids[i] == -1) {
				dfs(i);
			}
		}
	}
	void printNodes() {
		for (int i = 0; i < n; i++) {
			cout << "node " << i << "'s elements: {";
			for (size_t node = 0; node < g[i].size(); node++) {
				int& a = g[i][node];
				cout << a;
				if (((node + 1) - g[i].size()))cout << ", ";
			}
			cout << '}' << endl;
		}
	}
	void addEdge(int v, int u) {
		g[v].push_back(u);
	}
};

int main() {
	int n;
	cin >> n;

	Graph g(n);

	for (int i = 0; i < n; i++) {
		g.addEdge(i, (i + 1) % n);
		g.addEdge((i + 1) % n, i);
	}
	g.printNodes();
	g.buildSCCS();
	cout << g.SCCSCount;
}
