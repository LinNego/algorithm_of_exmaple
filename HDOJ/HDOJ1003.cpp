#include <iostream>
using namespace std;
const int maxn = 100005;
const int inf = 100000005;
int a[maxn];
int main() {
    int n;
    cin >> n;
    getchar();
    for(int j = 1; j <= n; ++j) {
        int k;
        cin >> k;
        for(int m = 1; m <= k; ++m) {
            cin >> a[m];
        }
        int b = 1, cnt = -inf, cur_sum = -inf;
        int tb, te;
        for(int i = 1; i <= k; ++i) {
            if(cur_sum <= 0) {
                cur_sum = a[i];
                b = i;
            }
            else {
                cur_sum += a[i];
            }
            if(cur_sum > cnt) {
                tb = b;
                te = i;
                cnt = cur_sum;
            }
        }
        cout << "Case " << j << ":\n";
        cout << cnt << " " << tb << " " << te << endl;
        if(j != n) cout << endl;
        
    }
    return 0;
}