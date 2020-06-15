/* 11.2.1 kruskal算法 */
#include <cstdio>
#include <algorithm>
const int maxn = 1000;
int w[maxn], p[maxn], u[maxn], v[maxn], r[maxn];
int cmp(const int i, const int j) {
	return w[i] < w[j];
}

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

int kruskal() {
	int ans = 0;
	for(int i = 0; i < n; ++i) 
		p[i] = i;
	for(int i = 0; i < m; ++i)
		r[i] = i;
	sort(r, r + m, cmp);
	for(int i = 0; i < m; ++i) {
		int e, u, v;
		e = r[i];
		u = find(p[e]);
		v = find(p[e]);
		if(u != v) {
			p[x] = y;
			ans += w[e];
		}
	}
	return ans;
}
int main() {
	
}
