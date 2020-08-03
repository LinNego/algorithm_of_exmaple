//HDOJ1874_Floyd.cpp
//LinNego

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int inf = ~(1 << 31);
const int maxn = 205;

int map[maxn][maxn];
int d[maxn][maxn];

int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF) {
        memset(map, -1, sizeof(map));
        int u, v, w; 
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i != j) map[i][j] = inf;
                else map[i][j] = 0;
            }
        }
        for(int i = 0; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            if(map[u][v] < 0 || map[u][v] > w) {
                map[u][v] = map[v][u] = w;
            }
        }                 
        int s, t;
        scanf("%d %d", &s, &t);
        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(map[i][k] < inf && map[k][j] < inf) {
                        map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
                       // printf("%d\n", map[i][j]);
                    }
                }
            }
        }
        printf("%d\n", map[s][t] == inf ? -1: map[s][t]);
        
    }
    return 0;
}