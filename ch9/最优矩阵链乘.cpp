//LinNego
//最优矩阵链乘.cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000;
const long long maxa = 10000000000;

struct maxtrix {
    int x, y;
};
maxtrix allm[maxn];
long long d[maxn][maxn], v[maxn][maxn];

long long dp(int i, int j) {
    if(i == j) {
        v[i][j] = 1;
        return d[i][j] = 0;
    }
    if(v[i][j]) return d[i][j];
    d[i][j] = maxa;
    v[i][j] = 1;
    for(int k = i; k < j; ++k) {
        int temp = allm[i].x * allm[k + 1].x * allm[j].y;
       // cout << temp << endl;
        d[i][j] = min(dp(i, k) + dp(k + 1, j) + temp, d[i][j]);
    }
    return d[i][j];
}

/*递推*/
void dps(int n) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i != j) d[i][j] = maxa;
            else d[i][j] = 0;
        }
    }
    for(int len = 2; len <= n; ++len) {,,
        for(int i = 0; i + len <= n; ++i) {
            int j = i + len - 1;
            for(int k = i; k < j; ++k) {
                d[i][j] = min(d[i][k] + d[k + 1][j] + allm[i].x * allm[k + 1].x * allm[j].y, d[i][j]);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> allm[i].x >> allm[i].y;
    } 
    memset(v, 0, sizeof(v));
    dps(n);
    cout << d[0][n - 1] << endl;
    return 0;
}