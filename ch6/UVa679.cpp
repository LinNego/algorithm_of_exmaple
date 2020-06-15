//UVa679.cpp
//Greatljc
//status: time limit

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 20;
int par[1 << maxn];

int main() {
	int L;
	while(scanf("%d", &L) != EOF && L != -1) {
		for(int i = 0; i < L; ++i) {
			int d, l;
			scanf("%d %d", &d, &l);
			memset(par, 0, sizeof(par));	
			int dep = 1 << (d - 1), k;
			for(int j = 0; j < l; ++j) {		
				k = 1;
				while(k < dep) {
					par[k] = !par[k];
					if(!par[k]) {
						k = 2 * k + 1;
					}
					else {
						k = 2 * k;
					}
				}
			}	
			printf("%d\n", k);
		}
	}	
	return 0;
}