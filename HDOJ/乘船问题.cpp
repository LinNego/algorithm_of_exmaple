//乘船问题.cpp
//LinNego
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, c;
    while(cin >> n >> c&& n) {
        vector<int> w;
        int t;
        for(int i = 0; i < n; ++i) {
            cin >> t;
            w.push_back(t);
        }
        sort(w.begin(), w.end());     
        int i = 0, j = n - 1;
        int ret = 0;
        while(i <= j) {
            if(w[i] + w[j] <= c) {
                ++i;
                --j;
                ++ret;
            }
            else {
                --j;
                ++ret;
            }
        }
        cout << ret << endl;
    }
    return 0;
}