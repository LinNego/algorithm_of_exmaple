//HDOJ1162_abs.cpp
//LinNego

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 105;
const int maxe = maxn * (maxn - 1) / 2;  //what the fuck, I forget the number of edge;

int p[maxn];
int u[maxe], v[maxe], r[maxe];
double w[maxe];

bool cmp(int i, int j) {
    return w[i] < w[j];
}

int finds(int x) { return p[x] == x ? x: p[x] = finds(p[x]); }

int main() {
    int n;
    double f = 1.0;
    
    while(scanf("%d", &n) != EOF) {
        double x[maxn], y[maxn];
        for(int i = 1; i <= n; ++i) {
            scanf("%lf %lf", &x[i], &y[i]);
        }
        int m = 1;
        for(int i = 1; i <= n; ++i) {
            for(int j = i + 1; j <= n; ++j) {
                u[m] = i;
                v[m] = j;
                w[m] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
                r[m] = m;
                ++m;
            }
        }
        for(int i = 0; i <= n; ++i) {
            p[i] = i;
        }
        sort(r + 1, r + m, cmp);
        double ans = 0.0;
        for(int i = 1; i < m; ++i) {
            int e = r[i];
            int x = finds(u[e]), y = finds(v[e]);
            if(x != y) {
                p[x] = y;
                ans += w[e];
            }
        }
        printf("%.2f\n", ans);
    }
    return 0;
}