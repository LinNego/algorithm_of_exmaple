//TopSort
//Greatljc

#include <cstdio>

const int maxn = 1000;
int c[maxn];
int topo[maxn], n, t;
int G[maxn][maxn];

bool dfs(int u) {
	c[u] = -1;
	for(int v = 0; v < n; ++v) {
		if(G[u][v]) {
			if(c[v] < 0) return false;
			else if(!c[v] && !dfs(v)) return false;
		}
	}
	c[u] = 1;
	topo[--t] = u;
}

bool toposort() {
	t = n;
	memset(c, 0, sizeof(c));
	for(int i = 0; i < n; ++i) {
		if(!c[i] && !dfs(i)) return false;
	}
	return true;
