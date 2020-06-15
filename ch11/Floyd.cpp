#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000;
const int inf = ~(1 << 31);
int d[maxn][maxn];
void init(int n) {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(i == j) d[i][j] = 0;
			else d[i][j] = inf;
		}
	}

}

void read_graph(int m) {
	for(int i = 0; i < m; ++i) {
		int from, to, dist;
		scanf("%d %d %d", &from, &to, &dist);
		d[from][to] = dist;
	}
}

void Floyd(int n, int m) {
	init(n);
	read_graph(m);
	for(int k = 0; k < n; ++k) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(d[i][k] < inf && d[k][j] < inf) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}
}

void print(int n) {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(d[i][j] < inf)
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Floyd(n, m);
	print(n);
	return 0;
}