#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 1e7 + 5;

int vis[maxn];

int main() {
    long long n, m;
    cin >> n >> m;
    memset(vis, 0, sizeof(vis));
    int s = floor(sqrt(m) + 0.5);
    cout << s << endl;
    for(int i = 2; i <= s; ++i) {
            int index = i * i;
            //cout << "i" << i << " ";
            for(int j = index; j <= m; j += index) {
               // cout << j << " " << endl;
                if(j >= n) {
                    vis[j - n] = 1;
                }
            }
    }
    int cnt = 0;
    
    for(int i = 0; i < m; ++i) {
        if(!vis[i]) {
            ++cnt;
            printf("%d %lld\n", i, i + n);
        }
    }
    
    cout << cnt << endl;
    
    return 0;
}