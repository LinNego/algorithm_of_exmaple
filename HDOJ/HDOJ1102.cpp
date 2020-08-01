//HDOJ 1102
//LinNego

#include <iostream>
#include <algorithm>
using std::sort;
using std::cout;
using std::cin;
using std::endl;
const int maxs = 5000;
const int maxn = 105;
struct Side {
    int u, v, len;
    bool operator<(const Side &rhs) {
        return len < rhs.len;
    }
};
Side sides[maxs];
int p[maxn];

inline int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

int main() {
    int n;
    while(cin >> n && n) {
        int temp, t = 1;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= i; ++j) {
                scanf("%d", &temp);
            }
            for(int j = i + 1; j <= n; ++j) {
                scanf("%d", &temp);
                sides[t].u = i;
                sides[t].v = j;
                sides[t].len = temp;
                t++;
            }
        }
        for(int i = 1; i <= n; ++i) {
            p[i] = i;
        }
        int q, a, b;
        cin >> q;
        /*借鉴了discuss*/
        /*如果不这样，可能还需要搜索sides数组*/
        for(int i = 1; i <= q; ++i) {
            cin >> a >> b;
            int x = find(a);
            int y = find(b);
            p[x] = y;
        }
        /**********************************/
        sort(sides, sides + t);
        int ans = 0;
        for(int i = 1; i < t; ++i) {
            int x = find(sides[i].u);
            int y = find(sides[i].v);
            if(x != y) {
                ans += sides[i].len;
                p[x] = y;
            }
        }
        cout << ans << endl;
    }
    return 0;
}