//UVa712.cpp
//Greatljc

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

const int maxn = 1024;
const int maxn_check = 10;
int leave[maxn];
int num[maxn];
int main() {
	int n, p[maxn_check], cnt = 1;
	while(cin >> n && n != 0) {
		if(cnt != 1) {
			printf("\n\n");
		}
		printf("S-Tree  #%d:\n", cnt++);
		char buf;
		for(int i = 0; i < n; ++i) {
			cin >> buf >> p[i]; 
			getchar();
		}
		int t = 1 << n;
		for(int i = 0; i < t; ++i) {
			scanf("%1d", &leave[i]);
		}
		int m, check[maxn_check];
		cin >> m;
		for(int i = 0; i < m; ++i) {
			int cur = 1;
			for(int j = 0; j < n; ++j) {
				scanf("%1d", &num[j]);
			}
			for(int j = 0; j < n; ++j) {
				if(num[p[j] - 1] == 0) {
					cur = 2 * cur;
				}
				else {
					cur = 2 * cur + 1;
				}
			}
			printf("%d", leave[cur - t]);
		}
		printf("\n");
	}
	return 0;
}