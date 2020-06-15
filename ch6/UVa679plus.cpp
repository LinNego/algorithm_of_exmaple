//UVa679plus.cpp
//Greatljc

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 20;

int main() {
	int L;
	while(scanf("%d", &L) != EOF && L != -1) {
		for(int i = 0; i < L; ++i) {
			int d, l;
			scanf("%d %d", &d, &l);
			int k = 1;
			for(int i = 0; i < d - 1; ++i) {
				if(l % 2 == 1) {
					k = k * 2;
					l = (l + 1) / 2;
				}
				else {
					k = k * 2 + 1;
					l = l / 2;
				}
			}
			printf("%d\n", k);
		}
	}
	return 0;
}