//UVa437.cpp
//LinNego
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct bottom {
	int w, l;
};

bool judge(int x, int y, int x1, int y1) {
	return x < y && x1 < y1;
}
void get_otherdimention(int &x, int &y, int i, int j) {
	for(int k = 0; k < 3; ++k) {
		if(k != j) x = k;
	}
	for(int k = 0; k < 3; ++k) {
		if(k != j && k != x) y = k;
	}
}

const int maxn = 30;

int d[maxn][3], dim[maxn][3], n;
bottom maps[maxn][3];

int dp(int i, int j) {
	//printf("dead \n");
	int &ans = d[i][j];
	if(ans > 0) return ans;
	ans = dim[i][j];
	for(int k = 0; k < n; ++k) {
		for(int l = 0; l < 3; ++l) {
			//if(l != j) {   //大错误，我下意思的以为每个i都相等了。
			bool ok1, ok2;
			int x1, y1, x2, y2;
			get_otherdimention(x1, y1, i, j);
			get_otherdimention(x2, y2, k, l);
			ok1 = judge(dim[i][x1], dim[k][x2], dim[i][y1], dim[k][y2]);
			ok2 = judge(dim[i][x1], dim[k][y2], dim[i][y1], dim[k][x2]);
			//ok1 = judge(maps[k][l].w, maps[i][j].w, maps[k][l].l, maps[i][j].l);
			//ok2 = judge(maps[k][l].l, maps[i][j].w, maps[k][l].w, maps[i][j].l);
			if(ok1 || ok2) {
				//printf("l: %d\n", l);
				ans = max(ans, dp(k, l) + dim[i][j]);
			}
			//}
		}
	}
	return ans;
}

int main() {
	int  kase = 0;
	while(cin >> n && n) {
		memset(d, -1, sizeof(d));
		memset(maps, 0, sizeof(maps));
		for(int i = 0; i < n; ++i) {
			cin >> dim[i][0] >> dim[i][1] >> dim[i][2];
			sort(dim[i], dim[i] + 3);	
			/*
			maps[i][0].w = dim[i][1];
			maps[i][0].l = dim[i][2];
			maps[i][1].w = dim[i][0];
			maps[i][1].l = dim[i][2];
			maps[i][2].w = dim[i][0];
			maps[i][2].l = dim[i][1];
			*/
			
		}
		int ans = -1;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < 3; ++j) {
				ans = max(ans, dp(i, j));
			}
		}
		printf("Case %d: maximum height = %d\n", ++kase, ans);
	}
	return 0;
}