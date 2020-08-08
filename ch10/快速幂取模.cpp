#include <iostream>
using namespace std;

int pow_mod(int a, int n, int m) {
    if(n == 0) return 1;
    int x = pow_mod(a, n / 2, m);
    long long ans = (long long)x * x % m;
    if(n % 2) ans = (long long)ans * a % m;
    return (int)ans;
}

int main() {
    int a, n, m;
    cin >> a >> n >> m;
    cout << pow_mod(a, n, m);
}
