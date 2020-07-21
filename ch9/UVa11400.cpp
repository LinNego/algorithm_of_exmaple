//LinNego
//UVa11400.cpp

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1005;
const int maxvalue = (1000 + 10 * 100) * 100 + 1;  //最大费用的是这个

struct category {
	int v, k, c, l;
	bool operator<(const category &rhs) const {
		return v < rhs.v;
	}
};
category vkcl[maxn];

//int V[maxn], K[maxn], C[maxn], L[maxn];
int s[maxn], d[maxn];
int main() {
	int n;
	while(cin >> n && n) {
		for(int i = 1; i <= n; ++i)	{
			cin >> vkcl[i].v >> vkcl[i].k >> vkcl[i].c >> vkcl[i].l;
		}	
		sort(vkcl + 1, vkcl + n + 1);
		s[0] = 0;
		for(int i = 1; i <= n; ++i) {
			s[i] = s[i - 1] + vkcl[i].l;
			//cout << s[i] << endl;
		}
		d[0] = 0;
		for(int i = 1; i <= n; ++i) {
			d[i] = maxvalue;
			for(int j = 0; j < i; ++j) {
				d[i] = min(d[i], d[j] + (s[i] - s[j]) * vkcl[i].c + vkcl[i].k);
			}
		}
		cout << d[n] << endl;
	}
}
