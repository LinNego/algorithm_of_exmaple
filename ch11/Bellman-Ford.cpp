#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 1000;
const int inf = ~(1 << 31);
struct Edge {
	int from, to, dist;
	Edge(int from, int to, int dist): from(from), to(to), dist(dist) {}
};

struct Bellman_Ford {
	int n, m;
	int d[maxn], p[maxn];
	vector<Edge> edges;
	vector<int> G[maxn];
	Bellman_Ford(int n, int m): n(n), m(m) {}	
	void clear() {
		for(int i = 0; i < n; ++i) {
			G[i].clear();
		}
		edges.clear();
	}
	void read_graph() {
		clear();
		int from, to, dist;
		for(int i = 0; i < m; ++i) {
			scanf("%d %d %d", &from, &to, &dist);
			edges.push_back(Edge(from, to, dist));
			G[from].push_back(i);
		}
	}
	void Smp_Bellman_Ford(int s) {
		for(int i = 0; i < n; ++i) {
			d[i] = inf;
		}	
		d[s] = 0;
		for(int i = 0; i < n - 1; ++i) {
			for(int j = 0; i < m; ++j) {
				int from = edges[i].from, to = edges[i].to;
				if(d[from] < inf) {
					d[to] = min(d[to], d[from] + edges[i].dist);
				}
			}
		}
	}
	bool Fifo_Bellman_Ford(int s) {
		queue<int> q;
		int cnt[maxn], inq[maxn];
		memset(cnt, 0, sizeof(cnt));
		memset(inq, 0, sizeof(inq));
		for(int i = 0; i < n; ++i) {
			d[i] = inf;
		}
		d[s] = 0;
		q.push(s);
		inq[s] = 1;
		while(!q.empty()) {
			int u = q.front();
			inq[u] = 0;
			q.pop();
			for(int i = 0; i < G[u].size(); ++i) {
				Edge e = edges[G[u][i]];
				if(d[e.from] < inf && d[e.to] > d[e.from] + e.dist) {
					d[e.to] = d[e.from] + e.dist;
					p[e.to] = G[u][i];
					if(!inq[e.to]) {
						q.push(e.to);
						inq[e.to] = true;
						if(++cnt[e.to] > n) return false;
					}
				}
			}
		}
		return true;
	}
	void print() {
		for(int i = 0; i < n; ++i) {
			printf("%d\n", d[i]);
		}
	}
};
int main() {
	Bellman_Ford bf(5, 5);	
	bf.read_graph();
	bf.Fifo_Bellman_Ford(0);
	bf.print();
	return 0;
}