//HDOJ1233.cpp
//LinNego //最小生成树
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 105;
const int maxe = maxn * (maxn - 1) / 2 + 5;
struct Edge {
    int u, v, w;
    Edge() = default;
    bool operator<(const Edge &rhs) const {
        return w < rhs.w;
    }
};

Edge edges[maxe];
int p[maxn];

int finds(int x) { return p[x] == x ? x : p[x] = finds(p[x]); }
int main() {
    int n;
    while(cin >> n && n) {
        int m = n * (n - 1) / 2; 
        for(int i = 1; i <= m; ++i) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
        }
        sort(edges + 1, edges + m + 1);
        for(int i = 1; i <= n; ++i) {
            p[i] = i;
        }
        int ans = 0;
        for(int i = 1; i <= m; ++i) {
            int w = edges[i].w;
            int u = finds(edges[i].u);
            int v = finds(edges[i].v);
            if(u != v) {
                p[u] = v;
                ans += w;
            }
        }
        cout << ans << endl;
    } 
    return 0;
}