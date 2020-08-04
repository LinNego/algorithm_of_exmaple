//HDOJ 1162.cpp
//LinNego

#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 105;

struct Point {
    double x, y;
    int num;
};

struct Edge {
    Point u, v;
    double w;
    Edge(Point &u, Point &v, double w): u(u), v(v), w(w) { }
    bool operator<(const Edge &rhs) const {
        return w < rhs.w;
    }
};

vector<Point> points;
vector<Edge> edges;
int p[maxn];

double distance(Point &lhs, Point &rhs) {
    return sqrt(pow(lhs.x - rhs.x, 2) + pow(lhs.y - rhs.y, 2));
}

int finds(int x) { return p[x] == x ? x : p[x] = finds(p[x]) ;}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        points.clear();
        edges.clear();
        double x, y;
        Point t;
        for(int i = 1; i <= n; ++i) {
            scanf("%lf %lf", &t.x, &t.y);
            t.num = i;
            points.push_back(t);
        }
        for(int i = 0; i < points.size(); ++i) {
            for(int j = i + 1; j < points.size(); ++j) {
                double d = distance(points[i], points[j]);
                edges.push_back(Edge(points[i], points[j], d));
                edges.push_back(Edge(points[j], points[i], d));
            }
        }
        for(int i = 0; i <= n; ++i) {
            p[i] = i;
        }
        sort(edges.begin(), edges.end());
        double ans = 0.0;
        for(int i = 0; i < edges.size(); ++i) {
            Edge edge = edges[i];
            int x = finds(edge.u.num), y = finds(edge.v.num);
            if(x != y) {
                p[x] = y;
                ans += edge.w;
            } 
        }
        printf("%.2f\n", ans);
    }
    return 0;
}