//test 循环n次和n - 1次的结果
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000;
const int inf = ~(1 << 31);
int w[maxn][maxn];
int d[maxn];
bool v[maxn];
void read_graph_ini(int n, int m) {
	for(int i = 0; i < n; ++i) {
		d[i] = inf;
	}	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			w[i][j] = inf;
		}
	}
	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v >> w[u][v];
	}

	memset(v, 0, sizeof(v));
}
//g->greater
void dijkstra_g(int n,  int b) {
	d[b] = 0;
	for(int i = 0; i < n; ++i) { 
		int mini = inf, x;
		for(int j = 0; j < n; ++j) {
			if(!v[j] && d[j] < mini) {
				mini = d[x = j];
			}
		}
		v[x] = 1;
		for(int j = 0; j < n; ++j) {
			//d[j] = min(d[j], d[x] + w[x][j]);
			if(d[x] < inf && w[x][j] < inf && d[j] < d[x] + w[x][j]) {
				d[j] = d[x] + w[x][j];
			}
		}

	}
}

//l->less
void dijkstra_l(int n, int m, int b) {
	d[b] = 0;
	for(int i = 0; i < n - 1; ++i) {
		int mini = inf, x;
		for(int j = 0; j < n; ++j) {
			if(!v[j] && d[j] < mini) {
				mini = d[x = j];
			}
		}
		v[x] = 1;
		for(int j = 0; j < n; ++j) {
			if(d[x] < inf && w[x][j] < inf && d[j] < d[x] + w[x][j]) {
				d[j] < d[x] + w[x][j];
			}
		}
	}
}
int main() {

}