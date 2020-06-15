//埃及分数.cpp
//Greatljc

#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn = 1000;
int ans[maxn], v[maxn];

int get_first(int a, int b) {
	return (int)ceil((float)b / a);
//	return b/a+1;
}

int maxd = 1;
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
bool better(int d) {
	for(int i = d; i >= 0; i--) {
		if(v[i] != ans[i]) {
			return ans[i] == -1 || v[i] < ans[i];
		}
	}
	return false;
}

bool dfs(int d, int from, int a, int b) {
	if(d == maxd) {
		if(b % a) return false;
		v[d] = b / a;    //卧槽，写成v[d] == b / a
		if(better(d)) memcpy(ans, v, sizeof(int) * (d + 1));
		return true;

	}
	int ok = 0;
	from = std::max(from, get_first(a, b));
	for(int i = from; ;++i) {
		if((maxd - d + 1) * b  <= i * a) break;
		v[d] = i;
		int bn = b * i;
		int an = a * i - b;
		int g = gcd(an, bn);
		if(dfs(d + 1, i + 1, an / g, bn / g)) ok = 1;
	}
	return ok;
}

int main() {
	int a, b;
	int kase = 1;
	scanf("%d %d", &a, &b);
	memset(ans, -1, sizeof(ans));
		int check = 0;
	for(maxd = 1; ;++maxd) {
		memset(ans, -1, sizeof(ans));
		if(dfs(0, get_first(a, b), a, b)) break;
	}
	printf("Case %d: 1/%d", kase++, ans[0]);
	for(int i = 1; i <= maxd; ++i) {
		printf("+1/%d", ans[i]);
	}	

	return 0;
}