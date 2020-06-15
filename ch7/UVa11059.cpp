//UVa11059.cpp
//LinNego
#include <cstdio>
const int maxn = 20;
int main() {
    int kase = 0, n, N[maxn];
    while(scanf("%d", &n) != EOF && n) {
        for(int i = 0; i < n; ++i) scanf("%d", &N[i]);
        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            long long v = 1;
            for(int j = i; j < n; ++j) {
                v *= N[j];
                if(v > ans) ans = v;
            }
        }
        //if(ans < 0) printf("%d\n", 0);
        //else
            printf("Case #%d: The maximum product is %lld.\n\n",++kase, ans);
    }
    return 0;
}