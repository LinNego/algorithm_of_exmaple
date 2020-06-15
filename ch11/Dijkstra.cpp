#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1000;
const int inf = ~(1 << 31);
struct Edge {
	int u, v, dist;  //不加边的序号的原因是使用数组存储边有自然的序号特征
	Edge(int u, int v, int d): u(u), v(v), dist(d) {}
};
struct HeapNode {
	int u, d;
	bool operator<(const HeapNode &rhs) const {
		return d > rhs.d;
	}
	HeapNode(int u, int d): u(u), d(d) {}
};
struct Dijkstra {
	vector<Edge> edges;
	vector<int> G[maxn];
	int n, m;
	int p[maxn];
	int d[maxn];
	int done[maxn];
	Dijkstra(int n): n(n) {
		for(int i = 0; i < this->n; ++i) {
			G[i].clear();
		}
		edges.clear();
	}

	void AddEdge(int u, int v, int dist) {
		edges.push_back(Edge(u, v, dist));
		m = edges.size();
		G[u].push_back(m - 1);
	}

	void dijkstra(int s) {
		priority_queue<HeapNode> q;
		q.push(HeapNode(s, 0));
		memset(done, 0, sizeof(done));
		for(int i = 0; i < n; ++i) {
			d[i] = inf; 
		}
		d[s] = 0;
		while(!q.empty()) {
			HeapNode t = q.top();
			q.pop();
			int u = t.u; 
			/* /这两句是不是不需要进行，理由如下，先前访问过的点必然是先前最小的，没访问过的。
			if(done[u]) continue;
			done[u] = true;
			*/
			for(int i = 0; i < G[u].size(); ++i) {
				Edge e = edges[G[u][i]];
				if(d[e.v] > d[e.u] + e.dist) {
					d[e.v] = d[e.u] + e.dist;
					p[e.v] = G[u][i]; //p[e.v] = e.u; 
					q.push(HeapNode(e.v, d[e.v]));
				}

			}

		}
	}
	void print() {
		for(int i = 0; i < n; ++i) {
			cout << d[i] << endl;
		}
	}
};
int main() {
	Dijkstra d(5);
	for(int i = 0; i < 5; ++i) {
		int u, v, dist;
		cin >> u >> v >> dist;
		d.AddEdge(u, v, dist);
	}
	d.dijkstra(0);
	d.print();
	return 0;
}