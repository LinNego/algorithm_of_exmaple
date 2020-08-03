//HDOJ1874_spfa.cpp
//LinNego

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int maxn = 205;
const int inf = ~(1 << 31);
struct Edge {
    int u, v, w;
    Edge(int u, int v, int w): u(u), v(v), w(w) { }
};

struct Bellman_Ford {
    vector<Edge> edges;
    vector<int> G[maxn];
    int n, m, s, t;
    int d[maxn], times[maxn];
    bool inq[maxn];
    Bellman_Ford(int n, int m): n(n), m(m) { 
        memset(inq, 0, sizeof(inq));
        memset(times, 0, sizeof(times));
    }

    void addEdge(Edge &edge) {
       edges.push_back(edge);
       G[edge.u].push_back(edges.size() - 1);
       edges.push_back(Edge(edge.v, edge.u, edge.w));
       G[edge.v].push_back(edges.size() - 1);
    }

    void st(int s, int t) {
        this->s = s;
        this->t = t;
    }

    bool bellman_ford() {
        queue<int> q;
        q.push(s);
        for(int i = 0; i < n; ++i) d[i] = inf;
        d[s] = 0;
        inq[s] = true;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            //if(u == t) break;
            /*what the fuck */
            /* I make inq[s] = false; */
            inq[u] = false;
            /**************************/
            for(int i = 0; i < G[u].size(); ++i) {
                Edge &edge = edges[G[u][i]];
                int v = edge.v;
                if(d[v] > d[u] + edge.w) {
                    d[v] = d[u] + edge.w;
                    if(!inq[v]) {
                        q.push(v);
                        inq[v] = true;
                        //if(++times[v] >= n) return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF) {
        Bellman_Ford bef(n, m);
        Edge edge(0, 0, 0);
        for(int i = 0; i < m; ++i) {
            scanf("%d %d %d", &edge.u, &edge.v, &edge.w);
            bef.addEdge(edge);
        }
        int s, t;
        scanf("%d %d", &s, &t);
        
        bef.st(s, t);
        bef.bellman_ford();
        printf("%d\n", bef.d[t] == inf ? -1: bef.d[t]);
        /*
        if(bef.bellman_ford() && bef.d[t] != inf) {
            printf("%d\n", bef.d[t]);
        }
        else {
            printf("%d\n", -1);
        }
        */
    }
    return 0;
}