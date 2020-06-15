#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const long long maxn = 10000000 + 5;
int vis[maxn], ans[maxn];
void ListPime(int m) {
	int ob = sqrt(sqrt(m + 0.5) + 0.5); //1.这里求开方的开方。向下取了整。
	memset(vis, 0, sizeof(vis));
	for(int i = 2; i <= ob; ++i) {       //2.是可以求出根号m的素数。
		if(!vis[i]) {
			for(int j = i * i; j <= m; j += i) {
				vis[j] = 1;	
			}
		}
	}
	return ;
}
//开方之后再平方可能会有误差，很致命。
void Solve(int n, int m) {
	ListPime(m);
	int ob = sqrt(m + 0.5);
	printf("%d\n", ob);
	memset(ans, 0, sizeof(ans));
	for(int i = 2; i <= ob; ++i) {
		if(!vis[i]) {
			int index = i * i;
			for(int j = index; j <= m; j += index) {
				if(j >= n) {
					ans[j] = 1;
				}
			}
		} 

	}		
}
int main() {
	int n, m;
	cin >> n >> m;
	Solve(n, m);
	int tol = 0;
	for(int i = n; i <= m; ++i) {
		if(ans[i]) {
			printf("%d ", i);
			++tol;
		} 
	}
	printf("\n");
	printf("tol: %d\n", tol);
	return 0;
}