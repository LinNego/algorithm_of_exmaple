//HDOJ1232.cpp
//LinNego

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int maxn = 1005;
int p[maxn];

int finds(int x) { return p[x] == x ? x : p[x] = finds(p[x]); }
int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) !=  EOF/*cin >> n >> m*/ && n) {
        for(int i = 1; i <= n; ++i) {
            p[i] = i;
        }
        int t = n, a, b;
        for(int i = 1; i <= m; ++i) {
           scanf("%d %d", &a, &b);
        //    cin >> a >> b;
           int x = finds(a), y = finds(b);
           if(x != y) {
               p[x] = y;
               --t;
           }
        }
        printf("%d\n", t - 1);
        //cout << t - 1<< endl;
    }
    return 0;
}