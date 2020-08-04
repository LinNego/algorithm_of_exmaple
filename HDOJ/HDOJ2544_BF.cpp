//HDOJ2544_BF.cpp
//LinNego

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int maxn = 105;
const int inf = ~(1 << 31);

struct Edge {
    int u, v, w;
    Edge(int u = 0, int v = 0, int w = 0): u(u), v(v), w(w) { }
};

struct Bellman_Ford {
    int n, m, s, t;
    vector<Edge> edges; 
    vector<int> G[maxn];
    int d[maxn];
    bool inq[maxn];
    int cnt[maxn];
    Bellman_Ford(int n, int m): n(n), m(m), s(1), t(n) { 
        memset(inq, 0, sizeof(inq));
        memset(cnt, 0, sizeof(cnt));
    }

    void add_edge(Edge &edge) {
        edges.push_back(edge);
        G[edge.u].push_back(edges.size() - 1);
        edges.push_back(Edge(edge.v, edge.u, edge.w));
        G[edge.v].push_back(edges.size() - 1);
    }

    bool bellman_ford() {
        for(int i = 1; i <= n; ++i) {
            d[i] = inf;
        }
        d[s] = 0;
        queue<int> q;
        q.push(1);
        inq[s] = true;
        while(!q.empty()) {
            int u = q.front();
            q.pop(); 
            inq[u] =  false;
            for(int i = 0; i < G[u].size(); ++i) {
                Edge &edge = edges[G[u][i]];
                if(d[edge.v] > d[edge.u] + edge.w) {
                    d[edge.v] = d[edge.u] + edge.w;
                    if(!inq[edge.v]) {
                        q.push(edge.v);
                        if(++cnt[edge.v] >= n) return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF && (n != 0 || m != 0)) {
        Bellman_Ford bf(n, m);
        Edge edge;
        for(int i = 1; i <= m; ++i) {
            scanf("%d %d %d", &edge.u, &edge.v, &edge.w);
            bf.add_edge(edge);
        }
        bf.bellman_ford();
        printf("%d\n", bf.d[n]);
    }
    return 0;
}