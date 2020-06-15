#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<sstream>
#include<map>
#include<stack>
using namespace std;
typedef long long LL;
const LL BIG = 1000;
LL ans[BIG],now[BIG],maxd;
LL find_best(LL a,LL b){ //满足1/c<=a/b的最小c
    return b/a+1;
}
LL gcd(LL a,LL b){
    return b == 0 ? a : gcd(b, a%b); //求最大公约数
}
bool better(LL depth){ //更新最优值，如果当前解now比之前最优解ans更优，则更新ans
    for(LL d = depth;d>=0;d--)
        if(now[d]!=ans[d]) return ans[d]==-1||now[d]<ans[d];//（1）此时的深度尚未找到解（2）当前的分母小于之前解的分母，说明当前深度为d的分数比之前的分数大，则可以替换。否则不替换
    return false;
}
//当前深度为deep,接下来的分母不能小于next,接下来的分式之和恰好为aa/bb
bool dfs(LL deep,LL next,LL aa,LL bb){
    bool ok;
    if(deep==maxd){//此时到达了最后一层
        if(bb%aa) return false; //bb不能整除aa(aa!=1)，构成不了埃及分式
        now[deep] = bb/aa;//取分母
        memcpy(ans, now, sizeof(long long)*(deep+1));//找到了更优的解，更新ans
        return true;
    }
    ok = false;
    next = max(next,find_best(aa, bb)); //更新next
    for(LL i = next;;i++){//枚举分母
        if((maxd+1-deep)*bb<=i*aa) break; //利用乐观估价函数来剪枝，从当前深度的接下来(maxd+1-deep)项分式，如果(1/i)*(maxd+1-deep)还凑不够aa/bb，则需要剪枝
        now[deep] = i;//更新当前深度的分母
        LL b2 = bb*i;//计算(aa/bb) - (1/i)，通分后的分母是bb*i，分子是aa*i-bb
        LL a2 = aa*i-bb;
        LL g = gcd(a2, b2);//计算最大公约数，用于约分
        if(dfs(deep+1, i+1, a2/g, b2/g)) ok = true;
    }
    return ok;
}
void to_do(LL a,LL b){
    int check = 0;
    for(maxd = 1;;maxd++){
        memset(ans, -1, sizeof(ans));
        if(dfs(0,find_best(a,b),a,b)){
            check = 1;break;
        }
    }
    if(check){
        for(int i = 0;i<maxd;i++) printf("1/%lld+",ans[i]);
        printf("1/%lld\n",ans[maxd]);
    }else{
        printf("NO ANSWER!");
    }
}
int main(){
    LL a,b;
    while(scanf("%lld%lld",&a,&b)!=EOF) to_do(a,b);
    return 0;
}
 