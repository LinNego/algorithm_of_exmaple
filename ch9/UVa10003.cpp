#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 50;
const int maxl = 1005;
const int inf = 100000000;

int d[maxl][maxl], vis[maxl][maxl];
int a[maxn];
int len, n;

int dp(int i, int j) {
    if(vis[i][j]) return d[i][j];
    d[i][j] = inf;
    vis[i][j] = 1;
    bool flag = 0;
    for(int k = 0; k < n; ++k) {
        //printf("kkk%d\n", a[k]);
        if(a[k] > i && a[k] < j) {
            flag = 1;
            d[i][j] = min(d[i][j], dp(i, a[k]) + dp(a[k], j) + j - i);
         //   printf("%d\n", d[i][j]);
        }
    }
    if(flag == 0) {
        d[i][j] = 0;
    }
   // printf("i %d j %d d[][] %d\n", i, j, d[i][j]);
    return d[i][j];
}
int main() {
    while(scanf("%d", &len) && len) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        memset(vis, 0, sizeof(vis));
        int ans = dp(0, len);
        printf("The minimum cutting is %d.\n", ans);

    }
    return 0;
}