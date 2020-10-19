#include<iostream>
#include<vector>
#include<memory.h> // for memset fuction
#include<algorithm> // should be included always XD

using namespace std;

// written by Iyaad M. Alazzam 
// 10/20/2020    2:33AM (GTM +1)
// the graph must has one component with n-1 edges ( tree ).
// Graph g(size_t size);
// it usually uses for undirected graph


class Graph {

	vector<vector<int>> g;
	vector<int> subtree;
	bool* vis;
	int* children;
	size_t size;

public:
	Graph(int siz) {

		size = siz;
		
		++++size;

		vis = new bool[size];
		children = new int[size];
		g.resize(size);
	}

	~Graph() {
		delete[] vis, children;
		vis = NULL, children = NULL;
	}
	
	void restGraphData() {
		//memset(vis, 0, sizeof(vis));
		//memset(children, 0, sizeof(children));
		for (size_t i = 0; i < size; i++) {
			g[i].clear();
			vis[i] = 0;
			children[i] = 0;
		}
	}

	int getChildren(int v) {

		vis[v] = 1;
		children[v] = 0;

		for (auto& a : g[v]) {

			if (vis[a] == 1)continue;

			children[v] += getChildren(a);


		}
		return 1 + children[v];

	}

	void dfs(int at) {
		static int num = 0;
		if (!num)num = children[at];
		//if (vis[at])
		//	return;
		//vis[at] = 1;
		for (auto& a : g[at]) {
			if ( children[a] < num) {
				subtree.push_back(a);
				dfs(a);
			}
		}
	}

	#define child(v) getChildrenNumber(v)
	int getChildrenNumber(int node) {
		return children[node];
	}
	
	void getNodeChildren(int node) {
		
		if (subtree.size()) {
			subtree.clear();
		}
		//memset(vis, 0, sizeof(vis));
		
		dfs(node);
		
		cout << "The children of the " << node << "-th node are: {";
		size_t siz = subtree.size();
		for (size_t i = 0; i < siz; i++) {
			cout << subtree[i];
			if (i + 1 != siz) cout << ", ";
		}cout << "}\n";
	
	}
	void addEdge(int v, int u) {
		g[v].push_back(u);
	}
};

int main() {
	Graph g(6);
	//for (int i = 0; i < 5; i++) {
		g.addEdge(0, 1);
		g.addEdge(0, 2);
		g.addEdge(2, 3);
		g.addEdge(2, 4);
		g.addEdge(1, 5);

		g.getChildren(0);

		cout << g.child(0) << endl;

		g.getNodeChildren(0);
		g.getNodeChildren(2);
	//}
	//G.child(5);
}