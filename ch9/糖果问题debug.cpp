//糖果问题debug.cpp
#include <cstdio>
#include <algorithm>
using std::min;

const int maxk = 20;
const int maxn = 105;

int dp[1 << maxk];
int a[maxn];

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int t;
    for(int i = 0; i < n; ++i) {
        int pos = 0;
        for(int j = 0; j < k; ++j) {
            scanf("%d", &t);
            --t;
            pos |= (1 << t);
        }    
        a[i] = pos;
    }
    
    for(int i = 0; i < 1 << maxk; ++i) {
        dp[i] = 0x3f;
    }
    dp[0] = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = (1 << m) - 1; j >= 0; --j) {
            dp[j | a[i]] = min(dp[j | a[i]], dp[j] + 1);
        }
    }
    printf("%d\n", dp[(1 << m) - 1]);
    return 0;
}
