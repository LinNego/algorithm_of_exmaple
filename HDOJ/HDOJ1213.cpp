//LinNego
//HDOJ1213.cpp

#include <cstdio>
using namespace std;

const int maxn = 1005;

int p[maxn];
int finds(int x) { return p[x] == x ? x : p[x] = finds(p[x]); }

int main() {
    int T;
    scanf("%d", &T); 
    while(T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; ++i) {
            p[i] = i;
        }
        int ans = n, a, b;
        for(int i = 1; i <= m; ++i) {
            scanf("%d %d", &a, &b); 
            int x = finds(a), y = finds(b);
            if(x != y) {
                p[x] = y;
                --ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}