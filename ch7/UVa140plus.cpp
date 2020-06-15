//UVa140plus.cpp
//Greatljc

#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

const int maxn = 26;

int graph[maxn][maxn];
int c[maxn], visit[maxn], pos[maxn], ans[maxn], tans[maxn];
int start, n;

int mini;

bool ini_graph(string &g) {
	memset(graph, 0, sizeof(graph));
	memset(c, 0, sizeof(c));
	mini = 400000;
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
	tans[cur] = u;
	pos[u] = cur;
	for(int i = 0; i <= cur; ++i) {
		if(graph[u][tans[i]] && visit[tans[i]] != 0) {
			int d = abs(cur - i);
			max_band = max(max_band, d);
		}
	}
	if(max_band >= mini) {
		return ;
	}
	for(int v = 0; v < 26; ++v) {
		if(c[v] && !visit[v]) {
			visit[v] = 1;
			dfs(v, max_band, cur + 1);
			visit[v] = 0;
		}
	}		
	if(cur == n - 1) {	
		if(max_band < mini) {
			memcpy(ans, tans, sizeof(tans));
			mini = max_band;
		}
		return ;
	}
}

int main() {
	string g;
	while(ini_graph(g)) {
		memset(visit, 0, sizeof(visit));
		memset(ans, 0, sizeof(ans));
		memset(tans, 0, sizeof(tans));
		for(int i = 0; i < 26; ++i) {
			if(c[i]) {
				visit[i] = 1;
				dfs(i, 0, 0);		
				visit[i] = 0;
			}
		}	
		for(int i = 0; i < n; ++i) {
			printf("%c ", ans[i] + 'A');
		}
		printf("-> %d\n", mini);
	}
	return 0;
}