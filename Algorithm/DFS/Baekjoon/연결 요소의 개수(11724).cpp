#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Graph {
private:
	int component;
	int node_num;
	vector<vector<int>> node_edge;
	vector<bool> visited;
	void DFS(int current) {
		visited[current] = true;
		for (int next : node_edge[current]) {
			if (!visited[next])	DFS(next);
		}
	}
public:

	/*constructor*/
	Graph(int N) {
		component = 0;
		node_num = N;
		node_edge.resize(N);
		visited.resize(N);
	}

	/*add edge*/
	void addEdge(int u, int v) {
		node_edge[u].push_back(v);
		node_edge[v].push_back(u);
	}

	/*sort edge along size of the number*/
	void sort_Edge() {
		for (int i = 0; i < node_num; i++) {
			sort(node_edge[i].begin(), node_edge[i].end());
		}
	}

	void DFS() {
		fill(visited.begin(), visited.end(), false);
		for (int i = 0; i < node_num; i++) {
			if (!visited[i]) {
				DFS(i);
				component++;
			}
		}

	}

	int getComponent() {
		return component;
	}
};

int main() {
	int N, M;
	int u, v;
	cin >> N >> M;
	Graph graph(N);
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		u--;
		v--;
		graph.addEdge(u, v);
	}
	graph.sort_Edge();
	graph.DFS();
	cout << graph.getComponent() << endl;
	
	return 0;
}