//LinNego
//HDOJ2544.cpp
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 105;
const int inf = ~(1 << 31);

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w): u(u), v(v), w(w) { }
};

struct Node {
    int u, d;
    Node(int u, int d): u(u), d(d) { }
    bool operator<(const Node &rhs) const {
        return d > rhs.d;
    }
};

struct Dijkstra {
    int n, m, s, t;
    int vis[maxn], d[maxn];
    vector<Edge> edges;
    vector<int> G[maxn];
    Dijkstra(int n, int m): n(n), m(m), s(1), t(n) {
        memset(vis, 0, sizeof(vis));
        edges.clear(); 
        for(int i = 0; i < maxn; ++i) {
            G[i].clear();
        }
    }

    void add(Edge &edge) {
        edges.push_back(edge);
        G[edge.u].push_back(edges.size() - 1);
        edges.push_back(Edge(edge.v, edge.u, edge.w));
        G[edge.v].push_back(edges.size() - 1);
    }

    void dijkstra() {
        for(int i = 0; i < maxn; ++i) {
            d[i] = inf;
        }
        d[s] = 0;
        vis[s] = 0;
        priority_queue<Node> q;
        q.push(Node(s, 0));
        while(!q.empty()) {
            Node from = q.top();
            q.pop();
            int u = from.u;
            if(from.u == t) break;
            if(vis[u]) continue;
            vis[u] = 1;
            for(int i = 0; i < G[u].size(); ++i) {
                Edge to = edges[G[u][i]];
                int v = to.v;
                if(d[v] > d[u] + to.w) {
                    d[v] = d[u] + to.w;
                    q.push(Node(v, d[v]));
                }
            }
        }
    }

};

int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF && (n || m)) {
        Dijkstra dij(n, m);
        Edge edge(0, 0, 0);
        for(int i = 0; i < m; ++i) {
            scanf("%d %d %d", &edge.u, &edge.v, &edge.w);
            dij.add(edge);
        }
        dij.dijkstra();
        printf("%d\n", dij.d[n]);
    }
    return 0;
}