//LinNego
//UVa1025.cpp
#include <cstdio>
#include <cstring>
#include <iostream>
using std::min;

const int maxn = 50 + 5;
const int maxt = 200 + 5;
const int INF = 1000000000;

int t[maxn], has_train[maxt][maxn][2];
int dp[maxt][maxn];

int main() {
	int n, T, kase = 0;
	while(scanf("%d %d", &n, &T) != EOF && n) {
		for(int i = 1; i <= n - 1; ++i) {
			scanf("%d", &t[i]);
		}
		memset(has_train, 0, sizeof(has_train));

		int m1, m2, d;
		scanf("%d", &m1);
		while(m1--) {
			scanf("%d", &d);
			for(int i = 1; i <= n - 1; ++i) {
				if(d <= T) has_train[d][i][0] = 1;
				d += t[i];
			}
		}
		scanf("%d", &m2);
		while(m2--) {
			scanf("%d", &d);
			for(int i = n - 1; i >= 1; --i) {
				if(d <= T) has_train[d][i + 1][1] = 1;  //[i + 1] 很容易错误
				d += t[i];
			}
		}

		for(int i = 1; i <= n - 1; ++i) dp[T][i] = INF;
		dp[T][n] = 0;
		for(int i = T - 1; i >= 0; --i) {
			for(int j = 1; j <= n; ++j) {
				dp[i][j] = dp[i + 1][j] + 1;
				if(j < n && has_train[i][j][0] && i + t[j] <= T) {
					dp[i][j] = min(dp[i][j], dp[i + t[j]][j + 1]);
				}
				if(j > 1 && has_train[i][j][1] && i + t[j - 1] <= T) {
					dp[i][j] = min(dp[i][j], dp[i + t[j - 1]][j - 1]);
				}
			}
		}
		printf("Case Number %d: ", ++kase);
		if(dp[0][1] >= INF) printf("impossible\n");
		else printf("%d\n", dp[0][1]);

	}
	return 0;
}