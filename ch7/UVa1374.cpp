//Greatljc
//UVa1374.cpp
#include <cstdio>
#include <cstring>

const int maxn = 1000;
int vis[maxn * 2 + 1], dex[maxn * 2 + 1];

int n, maxd, ans, ok;

void dfs(int d, int cur, int cnt) {
	if(d == maxd) {
		if(cur == n && cnt < ans) {
			ans = cnt;
			ok = 1;
		}
		return ;
	}
	if(dex[d] * (1 << maxd - d) < n) return ;
	for(int i = d; i >= 0; --i) {
		for(int j = d; j >= 0; --j) {
			int now_weight = dex[i] + dex[j];
			if(!vis[now_weight]) {
				vis[now_weight] = 1;
				dex[d + 1] = now_weight;
				dfs(d + 1, now_weight, cnt + 1);
				vis[now_weight] = 0;	
				if(ok) return ;
			}
			now_weight = dex[i] - dex[j];
			if(now_weight >= 0 && !vis[now_weight]) {
				vis[now_weight] = 1;
				dex[d + 1] = now_weight;
				dfs(d + 1, now_weight, cnt + 1);
				vis[now_weight] = 0;	
				if(ok) return ;
			}
		}
	}
}

int main() {
	while(scanf("%d", &n) != EOF && n) {
		
		if(n == 1) {
			printf("0\n");
			continue;
		}
		
		for(maxd = 1; ; ++maxd) { //理论上不会超过1000
			memset(vis, 0, sizeof(vis));	
			vis[1] = 1;  //代表指数为1
			dex[0] = 1;  //第一个指数
			ok = 0;
			ans = 3000;
			dfs(0, 1, 0);
			if(ok) break;
		}
		printf("%d\n", ans);
	}
	return 0;
}