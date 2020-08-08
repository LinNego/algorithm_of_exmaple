//除法表达式.cpp
//LinNego
//问题:为什么说E = (X1 * X3 * X4 * ... * Xk) / X2 不为整数，那么整个除法表达式就不可能为整数了呢？
//考虑这样：X1 X3 X4 ... Xk 分别 和 X2 除以他们各自的约数，如果最后不为整数，最后得到的式子 (X1' * X3' * X4' * ... *Xk') / X2' ，那么分子任何一个Xk'(k = 3, 4, ...) 和 X2'必然是互质的
//如果将分子的某一个Xk'移进分母，那么分子的其他Xn'最多就和Xk'相消，那么还是能得到一个互质的，X2'还是没能消
//所以综上所述，E = (X1 * X3 * X4 * ... * Xk) / X2不为整数，无论怎么移动Xk(k = 3, 4... )，都不可能得到整数。
//这只是非形式化的证明。 
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

const int maxn = 10005;

int x[maxn];

int gcd(int a, int b) {
    return b == 0 ? a: gcd(b, a % b);
}

bool judge(int m) {
    x[2] /= gcd(x[1], x[2]);
    for(int i = 3; i <= m; ++i) {
        x[2] /= gcd(x[2], x[i]);
    }
    return x[2] == 1;
}

int main() {
    int n;
    scanf("%d", &n);
    string str;
    while(n--) {
        cin >> str;
        int m = 0;
        for(int i = 0; i < str.size(); ++i) {
            if(str[i] != '/')
                x[++m] = str[i];
        }
        if(judge(m)) 
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}