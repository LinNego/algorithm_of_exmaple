//UVa524.cpp
//Greatljc

#include <cstdio>
#include <cstring>

const int maxn = 16;

int isp[maxn * 2], A[maxn], vis[maxn];
int n;

void get_primelist(int n) {
	for(int i = 2; i <= maxn * 2; ++i) {
		if(!isp[i]) {
			for(int j = i * i; j <= maxn * 2; j += i) {
				isp[j] = 1;
			}
		}
	}
}

void dfs(int cur) {
	if(cur == n && !isp[A[cur - 1] + A[0]]) {
		for(int i = 0; i < n; ++i) {
			printf("%d ", A[i]);
		}
		printf("\n");
		return ;
	}
	for(int i = 2; i <= n; ++i) {
		if(!vis[i] && !isp[i + A[cur - 1]]) {
			vis[i] = 1;
			A[cur] = i;
			dfs(cur + 1);
			vis[i] = 0;
		}
	}

}

int main() {	

	scanf("%d", &n);
	memset(vis, 0, sizeof(vis));
	memset(isp, 0, sizeof(isp));
	get_primelist(n);	
	A[0] = 1;
	dfs(1);


	return 0;
}