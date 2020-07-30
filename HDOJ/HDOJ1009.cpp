//HDOJ1009
//LinNego
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

const int maxn = 1005;
struct room {
    int j, f;
    double per;
    bool operator<(const room &rhs) const {
        return per > rhs.per;
    }
};

int main() {
    int M, N;
    while(cin >> M >> N && M != -1 && N != -1) {
        vector<room> r(maxn, room());
        for(int i = 0; i < N; ++i) {
            cin >> r[i].j >> r[i].f;
            //似乎需要考虑f == 0，没考虑似乎也AC了
        }
        for(int i = 0; i < N; ++i) {
            r[i].per = static_cast<double>(r[i].j) / static_cast<double>(r[i].f);
            //r[i].per = r[i].j / r[i].f;
        }
        double ret = 0.0;
        //float ret = 0.0 //精度不够，为啥？：
        int l = M;
        sort(r.begin(), r.end());
        for(int i = 0; i < N; ++i) {
            if(l > r[i].f) {
                ret += r[i].j;
                l -= r[i].f;
            }
            else {
                ret += (static_cast<double>(l) * r[i].per);
                break;
            }
        }
        printf("%.3lf\n", ret);

    }
    return 0;
}