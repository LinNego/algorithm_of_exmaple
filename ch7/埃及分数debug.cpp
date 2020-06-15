//埃及分数debug.cpp
//LinNego
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using std::max;
const int maxn = 1000;

long long v[maxn], ans[maxn];

long long get_first(long long a, long long b) {
	return (long long)ceil((double)b / a);
	//return b / a + 1;
}

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}
int flag;
bool better(long long d) {
	for(long long i = d; i >= 0; --i) {
		if(ans[i] != v[i]) return ans[i] == -1 || v[i] < ans[i];
	}
	return false;
}

long long maxd, ok;
void dfs(long long d, long long from, long long a, long long b) {
	if(d == maxd) {
		if(a == 0) {
			ok = 1;
			if(better(d)) memcpy(ans, v, sizeof(long long) * d);
		}
		return ;
	}
	from = max(from, get_first(a, b));
	for(long long i = from; ; ++i) {
		//printf("d: %d %d\n", d, i);
		v[d] = i;
		long long bn = b * i;
		long long an = a * i - b;
		long long g = 1;
		if(an) {
			if(bn * (maxd - d) <= i * an) break;			
			g = gcd(an, bn);
		}
		dfs(d + 1, i + 1, an / g, bn / g);
		if(ok) return ;
	}	
}

int main() {
	long long a, b, kase = 1;
	while(scanf("%lld %lld", &a, &b) != EOF) {
		for(maxd = 1; ; ++maxd) {
			flag = 0;
			ok = 0;
			memset(ans, -1, sizeof(ans));
			//if(a == 1) {ans[0] = b; break;}
			dfs(0, get_first(a, b), a, b);
			if(ok) break;
		}
		printf("Case %lld: ", kase++);
		for(long long i = 0; i < maxd; ++i) {
			if(i != 0) printf("+");
			printf("1/%lld", ans[i]); 
		}
		printf("\n");
	}
	return 0;
}