//HDOJ1874
//LinNego

#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

const int maxn = 205;
const int inf = ~(1 << 31);

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w): u(u), v(v), w(w) { }
};

struct Node {
    int u, d;
    Node(int u, int d): u(u), d(d) { }
    bool operator<(const Node &node) const {
        return d > node.d;
    }
};

struct Dijkstra {
    int n, m;
    int s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool vis[maxn];
    int d[maxn], p[maxn];
    Dijkstra(int n, int m): n(n), m(m) {
        edges.clear();
        for(int i = 0; i < maxn; ++i) {
            G[i].clear();
        }
        memset(vis, 0, sizeof(vis));
        memset(p, -1, sizeof(p));
    }
    void add(const Edge &edge) {
        edges.push_back(edge);
        G[edge.u].push_back(edges.size() - 1);
        Edge edge2(edge.v, edge.u, edge.w);
        edges.push_back(edge2);
        G[edge.v].push_back(edges.size() - 1);
    }
    void st(int s, int t) {
        this->s = s;
        this->t = t;
    }
    void dijkstra() {
        priority_queue<Node> q;
        q.push(Node(s, 0));
        for(int i = 0; i < maxn; ++i) {
            d[i] = inf;
        }
        d[s] = 0;
        //vis[s] = 1;
        while(!q.empty()) {
            Node from = q.top();
            q.pop();
            int u = from.u;
            if(u == t) break;
            if(vis[u]) continue;
            vis[u] = 1;
            for(int i = 0; i < G[u].size(); ++i) {
                Edge &e = edges[G[u][i]];
                if (/*!vis[e.v] && */ d[e.v] > d[e.u] + e.w) {
                    //vis[e.v] = 1;   
                    //在这里判断的而导致错误的原因是忽略了边权，并不是说第一次松弛就能得到最短
                    //并不是无权路
                    d[e.v] = d[e.u] + e.w;
                    Node to(e.v, d[e.v]);
                    q.push(to);
                    p[e.v] = G[u][i];
                }
            }
        }
    }

    /*is true but maybe have some problems*/
    /*because of undirected graph*/
    void print() {
        vector<Edge> road;
        while(p[t] != -1) {
            Edge temp = edges[p[t]];
            road.push_back(temp);
            t = temp.u;
        }
        for(int i = road.size() - 1; i >= 0; --i) {
            printf("%d %d %d\n", road[i].u, road[i].v, road[i].w);
        }
    }
};

int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF) {
        Dijkstra dij(n, m);
        for(int i = 0; i < m; ++i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            dij.add(Edge(u, v, w));
        }
        int s, t; 
        scanf("%d %d", &s, &t);
        dij.st(s, t);
        dij.dijkstra();
        printf("%d\n", dij.d[t] == inf ? -1: dij.d[t]);
        dij.print();
    }
    return 0;
}