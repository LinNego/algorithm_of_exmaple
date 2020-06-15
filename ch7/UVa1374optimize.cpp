//Greatljc
//UVa1374optimize.cpp
#include <cstdio>
#include <cstring>

const int maxn = 1000;
int n, maxd, ok;
int dex[maxn * 2 + 1];


void dfs(int d, int cur_weight) {
	if(d == maxd) {
		if(cur_weight == n) ok = 1;
		return ;
	}
	if(dex[d] << (maxd - d) < n) return ;
	for(int i = d; i >= 0; --i) {
		dex[d + 1] = cur_weight + dex[i];
		dfs(d + 1, cur_weight + dex[i]);
		if(ok) return ;	
		dex[d + 1] = cur_weight - dex[i];
		if(dex[d + 1] >= 0) dfs(d + 1, cur_weight - dex[i]);
		if(ok) return ;
	}
}
int main() {
	while(scanf("%d", &n) != EOF && n) {
		dex[0] = 1;
		for(maxd = 1; ;++maxd) {
			ok = 0;
			dfs(0, 0);   //从0开始就可以统一n为1和其他的情况
			if(ok) break;
		}
		printf("%d\n", maxd - 1); //因为从0开始
	}
	return 0;
}