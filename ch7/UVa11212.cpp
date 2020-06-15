//UVa11212.cpp
//LinNego

#include <cstdio>
#include <cstring>

const int maxn = 9;
int n, a[maxn];

bool is_solve() {
	for(int i = 0; i < n - 1; ++i) {
		if(a[i] + 1 != a[i + 1]) return false;
	}
	return true;
}

int h() {
	int cnt = 0;
	for(int i = 0; i < n - 1; ++i) {
		if(a[i] + 1 != a[i + 1]) ++cnt;
	}
	if(a[n-1] != n) cnt++;           /*漏写这个代码，失去正确性*/
	return cnt;
}

bool dfs(int cur, int maxd) {
	if(3 * cur + h() > 3 * maxd) return false;
	if(is_solve()) return true;
	int b[maxn], old[maxn];
	memcpy(old, a, sizeof(a));
	for(int i = 0; i < n; ++i) {
		for(int j = i; j < n; ++j) {
			int cnt = 0;
			for(int k = 0; k < n; ++k) {
				if(k < i || k > j) b[cnt++] = a[k];
			}
			for(int k = 0; k <= cnt; ++k) {
				int cnt2 = 0;
				for(int p = 0; p < k; ++p) {
					a[cnt2++] = b[p];
				}
				for(int p = i; p <= j; ++p) {
					a[cnt2++] = old[p];
				}
				for(int p = k; p < cnt; ++p) {
					a[cnt2++] = b[p];
				}
				if(dfs(cur + 1, maxd)) return true;
				memcpy(a, old, sizeof(a));
			}
		}
	}
	return false;
}

int solve() {
	if(is_solve()) return 0;
	int maxt = 8;
	for(int maxd = 1; maxd <= maxt; ++maxd) {
		if(dfs(0, maxd)) return maxd;
	}
	return maxt;
}

int main() {
	int kase = 1;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
		printf("Case %d: %d\n", kase++, solve());
	}
	return 0;
}