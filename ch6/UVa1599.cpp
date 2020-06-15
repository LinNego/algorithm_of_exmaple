//UVa1599.cpp
//Greatljc

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
	int u, v, c;
	Edge(int u = 0, int v = 0, int c = 0): u(u), v(v), c(c) { }
};
const int maxn = 100000 + 5;
const int INF = 1000000000;

vector<Edge> edges;
vector<int>G[maxn];

int n, m;
/*
void AddEdge(int u, int v, int c) {
	edges.push_back(Edge(u, v, c));
	int idx = edges.size() - 1;
	G[u].push_back(idx);
}
*/
bool readGraph() {
	edges.clear();
	if(scanf("%d %d", &n, &m) != EOF) {
		for(int i = 0; i < n; ++i) G[i].clear();
		int u, v, color;	
		for(int i = 0; i < m; ++i) {
			scanf("%d %d %d", &u, &v, &color);
			edges.push_back(Edge(u - 1, v - 1, color)); 
			/*错误的想法。以为push_back一条边就行了，实际上不行。
			*因为这条边的起点是从u -> v。
			*也有一种想法，就是从当前点直接找到边的编号，可是如果只push一条边，并不知道结构体Edge
			*的u，v是当前点。
			*/			
			G[u - 1].push_back(edges.size() - 1);
			edges.push_back(Edge(v - 1, u - 1, color));
			G[v - 1].push_back(edges.size() - 1);
		}
		return true;
	}
	return false;
}

int dist[maxn], visit[maxn];
void rev_bfs() {
	//memset(dist, -1, sizeof(dist));
	memset(visit, 0, sizeof(visit));
	queue<int> q;
	dist[n - 1] = 0;
	visit[n - 1] = 1;  //problem
	q.push(n - 1);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = 0; i < G[u].size(); ++i) {
			int e = G[u][i];
			int v = edges[e].v;
			if(!visit[v]) {
				visit[v] = 1;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}
vector<int> ans;
void bfs() {
	ans.clear();
	memset(visit, 0 , sizeof(visit));
	visit[0] = 1;

	vector<int> next;
	next.push_back(0);
	for(int i = 1; i <= dist[0]; ++i) {
		int mincolor = INF;
		for(int j = 0; j < next.size(); ++j) {
			int u = next[j];
			for(int k = 0; k < G[u].size(); ++k) {
				int e = G[u][k];
				int v = edges[e].v;
				if(dist[u] == dist[v] + 1) {
					mincolor = min(mincolor, edges[e].c);
				}
			}
		}
		ans.push_back(mincolor);
		vector<int> next2;
		for(int j = 0; j < next.size(); ++j) {
			int u = next[j];
			for(int k = 0; k < G[u].size(); ++k) {
				int e = G[u][k];
				int v = edges[e].v;
				if(dist[u] == dist[v] + 1 && !visit[v] && edges[e].c == mincolor) {
					visit[v] = 1;
					next2.push_back(v);
				}
			}
		}
		next = next2;
	}

	printf("%d\n", ans.size());
	printf("%d", ans[0]);
	for(int i = 1; i < ans.size(); ++i) printf(" %d", ans[i]);
	printf("\n");
}
int main() {
	int u, v, c, m;
	/*
	while(scanf("%d %d", &n, &m) != EOF) {
		for(int i = 0; i < n; i++) G[i].clear();
		while(m--) {
			scanf("%d%d%d", &u, &v, &c);
			AddEdge(u - 1, v - 1, c);
			AddEdge(v - 1, u - 1, c);
		}
		rev_bfs();
		bfs();
	}
	*/
	while(readGraph()) {
		rev_bfs();
		bfs();
	}
	return 0;
}