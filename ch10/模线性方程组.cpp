//模线性方程组
//LinNego
//求解 ax === b(mod n)
//求 ax - b = yn;
//即 ax - ny = b;
#include <iostream>
using namespace std;

int gcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int ret = gcd(b, a % b, y, x);
    y -= x * (a / b);
    return ret;
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    int x, y;
    int g = gcd(a, -n, x, y);
    cout << x << " " << y << endl;
    return 0;
}