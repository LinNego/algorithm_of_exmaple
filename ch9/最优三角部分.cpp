//最优三角部分
//LinNego
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1000;

int v[maxn][maxn], d[maxn][maxn];
int va[maxn];
int w(int i, int k, int j) {
    return va[i] + va[k] + va[j];
}
int dp(int i, int j) {
    if(i + 1 == j) return d[i][j] = 0;
    if(v[i][j]) return d[i][j];
    v[i][j] = 1;
    d[i][j] = -1;
    for(int k = i + 1; k < j; ++k) {
        d[i][j] = max(d[i][j] , dp(i, k) + dp(k, j) + w(i, k, j));
    }
    return d[i][j];
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> va[i];
    }
    memset(v, 0, sizeof(v));
    cout << dp(0, n - 1) << endl;
    return 0;
}