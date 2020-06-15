//UVa129.cpp
//Greatljc

#include <cstdio>
#include <cstring>

const int maxn = 90;

int ans[maxn], cnt = 0;

bool dfs(int cur, int n, int L) {
	if(cnt++ == n) {
		int cc = 0;
		printf("%c", 'A' + ans[0]);
		for(int i = 1; i < cur; ++i) {
			if(i % 64 == 0) {
				printf("\n");
			}
			else if(i % 4 == 0) {
				printf(" ");
			}
			printf("%c", 'A' + ans[i]);
		}
		printf("\n%d\n", cur);
		return true;;
	}
	for(int i = 0; i < L; ++i) {
		ans[cur] = i;
		int ok = 1;
		for(int j = 1; j * 2 <= cur + 1; ++j) {
			int equal = 1;
			for(int k = 0; k < j; ++k) {
				if(ans[cur - k] != ans[cur - k - j]) {
					equal = 0;
					break;
				}
			}
			if(equal) {
				ok = 0;
				break;
			}
		}
		if(ok) {
			if(dfs(cur + 1, n, L)) {
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	int n, L;
	while(scanf("%d %d", &n, &L) == 2 && (n != 0 || L != 0)) {
		cnt = 0;
		memset(ans, 0, sizeof(ans));
		dfs(0, n, L);
	}
	return 0;
}