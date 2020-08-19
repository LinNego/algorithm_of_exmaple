//糖果问题.cpp
//LinNego

#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

const int maxn = 105;
const int maxk = 25;

struct Set {
    set<int> cur_stat;
    int dis;
    Set(int dis = 0): dis(dis) { }
    bool operator<(const Set &rhs) const {
        return dis < rhs.dis;
    }
};

set<int> suger[maxn];
set<Set> stats[maxn];


int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; ++i) {
        int temp;
        for(int j = 0; j < k; ++j) {
            scanf("%d", &temp);
            suger[i].insert(temp);
        }
    }
    for(int i = n; i >= 1; --i) {
        Set temp;
        vector<int> ve;
        set<int> temp_set;
        for(auto j: stats[i + 1]) {
            stats[i].insert(j);         //都不加的
            temp.cur_stat = j.cur_stat;
            set_difference(j.cur_stat.begin(), j.cur_stat.end(), suger[i].begin(), suger[i].end(), back_inserter(ve));  //这里有问题
            if(!ve.empty()) {
                temp.dis = j.dis + 1;
                for(auto l: ve) {
                    temp.cur_stat.insert(l);
                }
            }
            stats[i].insert(temp); 
        }
    }
    bool flag = 0;
    for(auto i: stats[1]) {
        if(i.cur_stat.size() == k) {
            flag = 1;
            printf("%d\n", i.dis);
            break;
        }
    } 
    if(!flag) printf("-1\n");
    return 0;
}