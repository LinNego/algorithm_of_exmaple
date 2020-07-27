//UVa1626.cpp
//LinNego
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1000;
const int n = 50;
const int inf = 100000000;

int d[maxn][maxn], vis[maxn][maxn];
int a[maxn], m;

int dp(int i, int j) {
    if(vis[maxn][maxn]) return d[i][j];
    vis[i][j] = 1; 
    d[i][j] = inf;
    for(int k = 0; k < m; ++k) {
        if(a[k] >= i && a[k] <= j) {
            d[i][j] = min(d[i][j], dp(i, k) + dp(k, j) + i - j);
        }
    }
    return d[i][j];
}

int main() {
    int l;
    while(cin >> l && l) {
        cin >> m;
        for(int i = 0; i < m; ++i) {
            cin >> a[i];
        }
        dp(0, n + 1)
        
    }
}