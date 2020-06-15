//UVa12325.cpp
//LinNego
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	int kase = 1;
	while(t--) {
		long long n;
		long long s1, v1;  //宝物1的价值的体积
		long long s2, v2;  //宝物2的价值和体积
		long long ans = 0, bound;
		scanf("%lld %lld %lld %lld %lld", &n, &s1, &v1, &s2, &v2);
		if(n / s1 < 65536) {
			bound = n / s1;
			for(long long i = 0; i <= bound; ++i) {
				ans = max(ans, i * v1 + (n - i * s1) / s2 * v2);
			}
		}
		else if(n / s2 < 65536) {
			bound = n / s2;
			for(long long i = 0; i <= bound; ++i) {
				ans = max(ans, i * v2 + (n - i * s2) / s1 * v1);
			}
		}
		else {
			if(s1 * v2 > s2 * v1) {
				swap(s1, s2);
				swap(v1, v2);
			}
			for(long long i = 0; i <= s1; ++i) {  //  =的原因是可能相等 s1*v2==s2*v1
				ans = max(ans, i * v2 + (n - i * s2) / s1 * v1);
			}
		}
		printf("Case #%d: %lld\n", kase++, ans);
	}
	return 0;
}