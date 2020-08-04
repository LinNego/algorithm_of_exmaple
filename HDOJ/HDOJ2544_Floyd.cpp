//HDOJ2544_Floyd.cpp
//LinNego

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 105;
const int inf = ~(1 << 31);

int d[maxn][maxn];

int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) && (n || m)) {
        for(int i = 0; i <= n + 1; ++i) {
            for(int j = 0; j <= n + 1; ++j){
                if(i != j) d[i][j] = inf;
                else d[i][j] = 0;
            }
        }
        int u, v, w;
        for(int i = 0; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &w) ;
            if(d[u][v] > w) {
                d[u][v] = d[v][u] = w;
            }
        }

        for(int k = 1; k <= n; ++k) {
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= n; ++j) {
                    if(d[i][k] < inf && d[k][j] < inf) {
                        d[i][j] = min(d[i][j], d[i][k] + d[j][k]);
                    }
                }
            }
        }
        printf("%d\n", d[1][n]);
    }
    return 0;

}