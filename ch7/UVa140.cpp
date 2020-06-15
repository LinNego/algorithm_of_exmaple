//UVa140.cpp
//Greatljc

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

const int maxn = 26;

int graph[maxn][maxn];
int c[maxn], visit[maxn], max_bands[maxn], pos[maxn], ans[maxn];
int start, n;

int mini = 4000000;

bool ini_graph(string &g) {
	memset(graph, 0, sizeof(graph));
	memset(c, 0, sizeof(c));
	n = 0;
	cin >> g;
	if(g[0] == '#') return false;
	int cur;
	for(int i = 0; i < g.size(); ++i) {
		cur = g[i];
		if(!c[cur - 'A']) {
			c[cur - 'A'] = 1;
			++n;
		}
		i += 2;
		while(i < g.size() && g[i] != ';') {
			if(!c[g[i] - 'A']) {
				c[g[i] - 'A'] = 1;
				++n;
			}
			graph[cur - 'A'][g[i] - 'A'] = 1;
			graph[g[i] - 'A'][cur - 'A'] = 1;
			++i;
		}
	}
	return true;
}

void dfs(int u, int max_band, int cur) {
	printf("%d\n", cur);
	if(max_band >= mini) {
		return ;
	}
	ans[cur] = u;
	//printf("%c ", ans[cur] + 'A');
	pos[u] = cur;
	for(int v = 0; v < 26; ++v) {	
		int nvisit = 0;
		int tmax_band = max_band;
		max_bands[u] = max(max_bands[u], nvisit);
		tmax_band = max(tmax_band, max_bands[u]);
		if(!visit[v] && c[v]) {
			visit[v] = 1;
			//printf("%d tmax_band\n", tmax_band);
			dfs(v, tmax_band, cur + 1);
			visit[v] = 0;
		}
		
		if(cur == n - 1) {
			for(int i = 0; i < n; ++i) {
				printf("%c ", 'A' + ans[i]);
			}
			printf("\n");
			printf("tmax_band%d\n", tmax_band);
			if(tmax_band < mini)
				mini = tmax_band;
		}
	}

}

void test_input() {
	for(int i = 0; i < 26; ++i) {
		for(int j = 0; j < 26; ++j) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
}



int main() {
	string g;
	while(ini_graph(g)) {
		//test_input();
		printf("%d n\n", n);
		memset(visit, 0, sizeof(visit));
		memset(ans, 0, sizeof(ans));
		for(int i = 0; i < 26; ++i) {
			memset(max_bands, 0, sizeof(max_bands));
			if(c[i]) {
				visit[i] = 1;
				dfs(i, 0, 0);			
				visit[i] = 0;
			}
		}	
		for(int i = 0; i < n; ++i) {
			printf("%c ", ans[i] + 'A');
		}
		printf("-> %d", mini);
	}
	return 0;
}