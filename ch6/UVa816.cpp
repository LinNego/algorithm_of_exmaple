//UVa816.cpp
//Greatljc  //liurujia

#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
struct Inter {
	int row, col, dir;
	Inter(int row, int col, int dir): row(row), col(col), dir(dir) {}
	Inter() = default;
};

const char* dirs = "NESW";
const char *drcs = "FLR";

int drc_id(char c) {
	return strchr(drcs, c) - drcs;
}
int dir_id(char c) {
	return strchr(dirs, c) - dirs;
}
int drr[4] = {0, 1, 0, -1};
int drc[4] = {1, 0, -1, 0};
int have_edge[9][9][4][3];
Inter par[9][9][4];
int d[9][9][4];
char s[100], s2[10];
int s_row, s_col, e_row, e_col, dir;
int ok;
bool Read_Case() {
	memset(have_edge, 0, sizeof(have_edge));
	memset(par, -1, sizeof(par));
	ok = 1;
	//char s[100], s2[10]//这里用数组的原因是为了浓缩代码
	while(scanf("%s%d%d%s%d%d", s, &s_row, &s_col, s2, &e_row, &e_col) == 6) {
		int row, col;
		if(s[0] == 'E') ok = 0;
		while(1) {
			if(scanf("%d%d", &row, &col) != 2) return true;
			while(scanf("%s", s) == 1 && s[0] != '*') {
				 dir = dir_id(s[0]);
				 int len = strlen(s2);
				for(int i = 1; i < len; ++i) {
					int dr = drc_id(s[i]);
					have_edge[row][col][dir][dr] = 1;
				}
			}
		}
	}
	return false;
}
Inter walk(Inter cur, int turn) {
	int dir = cur.dir;
	if(turn == 1) dir = (dir + 3) % 4;
	if(turn == 2) dir = (dir + 1) % 4;
	return Inter(cur.row + drr[dir], cur.col + drc[dir], dir);
}
bool inside(int r, int c) {
	return -1 < r < 9 && -1 < c < 9;
}
void print_ans(Inter u) {
	vector<Inter> nodes;
	for(;;) {
		nodes.push_back(u);
		if(d[u.row][u.col][u.dir] == 0) break;
		u = par[u.row][u.col][u.dir];
	}
	nodes.push_back(Inter(s_row, s_col, dir));

	int cnt = 0;
	for(int i = nodes.size() - 1; i >= 0; i--) {
		if(cnt % 10 == 0) printf(" ");
		printf(" (%d,%d)", nodes[i].row, nodes[i].col);
		if(++cnt % 10 == 0) printf("\n");
	}
	if(nodes.size() % 10 != 0) printf("\n");
}
void solve() {
	queue<Inter> que;
	memset(d, -1, sizeof(d));
	que.push(Inter(s_row, s_col, s2[0]));
	while(!que.empty()) {
		Inter cur = que.front();
		que.pop();
		if(cur.row == e_row && cur.col == e_col) {
			print_ans(cur);
			return ;
		}
		for(int i = 0; i < 3; ++i) {
			Inter u = walk(cur, i);
			if(have_edge[cur.row][cur.col][cur.dir][i] && inside(u.row, u.col) && d[u.row][u.col][u.dir] < 0) {
				d[u.row][u.col][u.dir] = d[cur.row][cur.col][cur.dir] + 1;
				par[u.row][u.col][u.dir] = u;
				que.push(u);
			}
			//距离d是什么
				
		}
	}
	printf("No Solution Possible\n");
}



int main() {
	while(Read_Case()) {
		solve();
	}
	
	return 0;
}