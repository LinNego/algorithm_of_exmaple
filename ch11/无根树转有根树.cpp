/* 11.1.1 无根树转有根树 */
/* 示例代码 */
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1000;
vector<int> G[maxn];
void readtree() {
	int n, u, v;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; ++i) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
}
int p[maxn];
void dfs(int x, int fa) {
	int size = G[x].size();
	for(int i = 0; i < size; ++i) {
		int t = G[x][i];
		if(t != fa) dfs(t, p[t] = x);
	}
}

int main() {
	int root;
	scanf("%d", &root);
	p[root] = -1;
	readtree();
	dfs(root, -1);
	return 0;
	
}
