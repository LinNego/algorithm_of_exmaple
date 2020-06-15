#include <cstdio>
#include <cstring>
#include <cstdlib>
const int maxn = 26;
const int maxa = 1000 + 1;
bool C[maxn], C2[maxn];
int G[maxn][maxn];
void is_connected(int u) {
	C[u] = 1;
	for(int v = 0; v < maxn; ++v) {
		if(!C[v] && G[u][v]) {
			is_connected(v);
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int m;
		scanf("%d", &m);
		memset(G, 0, sizeof(G));
		memset(C, 1, sizeof(C));
		for(int j = 0; j < m; ++j) {
			char A[maxa];
			scanf("%s", A);
			int len = strlen(A);
			int b = A[0] - 'a', e = A[len - 1] - 'a';
			C[b] = 0; C[e] = 0;
			++G[b][e];
		}
		int in[maxn], out[maxn], first_in = 0, first_out = 0;
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(in));
		for(int i = 0; i < maxn; ++i) {
			for(int j = 0; j < maxn; ++j) {
				in[i] += G[i][j];
				out[j] += G[i][j];
			}
		}
		/*
		for(int j = 0; j < maxn; ++j) {
			for(int i = 0; i < maxn; ++i) {
				out[j] += G[i][j];
			}
		}
		*/
		bool sign = 0, sign2 = 0;
		for(int i = 0; i < maxn; ++i) {
			if(in[i] - out[i] == 1 && !first_in) first_in = 1;
			else if(out[i] - in[i] == 1 && !first_out) first_out = 1;
			else if(in[i] == out[i]) continue;
			else {
				sign = 1;
				break;
			}
		}
		/*
		 * 忽略掉边的方向之后，图也需要连通性
		 *如果不需要打印路径（打印路径需要确定起点），那么下面的循环，让进行连通测试时不再需要从起点出发
		 */	
		for(int i = 0; i < maxn; ++i) {
			for(int j  = 0; j < maxn; ++j) {
				if(G[i][j] > 0) G[j][i] = G[i][j];
			}
		}

		is_connected(0);  //这里有bug  //这里需要找到一个点时确切输入的，如果没有输入过a，那么将发生bug，可是代码却ac了。
		for(int i = 0; i < maxn; ++i) {
			if(!C[i]) {
				sign2 = 1;
				break;
			} 
		}
		if(sign || sign2 ) {
			printf("The door cannot be opened.\n");
		}
		else {
			printf("Ordering is possible.\n");
		}
	}
	return 0;
	
}