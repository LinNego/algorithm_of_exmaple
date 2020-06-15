//八皇后问题
//LinNego

#include <cstdio>

const int maxn = 50;
int n, cnt;

int c[maxn];

void dfs(int cur) {
	if(cur == n) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(c[i] == j) printf("Q");
				else printf("#");	
			}
			printf("\n");
		}
		printf("\n\n");
		++cnt;
		return ;
	}
	for(int i = 0; i < n; ++i) {
		c[cur] = i;
		int ok = 1;
		for(int j = 0; j < cur; ++j) {
			if(c[cur] == c[j] || cur - c[cur] == j - c[j] || cur + c[cur] == j + c[j]) {
				ok = 0;
				break;
			}
		}
		if(ok) dfs(cur + 1);
	}
}

int main() {
	while(scanf("%d", &n) != EOF && n) {
		cnt = 0;
		dfs(0);
		printf("%d\n", cnt);
	}
	return 0;
}