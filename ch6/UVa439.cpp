//UVa439.cpp
//Greatljc

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Node {
	int x, y;
	Node(int x, int y) : x(x), y(y) {}
};

const int maxn = 8;
int d[maxn][maxn];

int row_change[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int col_change[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int start_row, start_col, end_row, end_col;

void analy_input(char *b, char *e) {
	start_col = b[0] - 'a';
	start_row = 8 - b[1] + '0';
	end_col = e[0] - 'a';
	end_row = 8 - e[1] + '0';
}

bool is_inbound(int x, int y) {
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}

void bfs() {
	queue<Node> q;
	q.push(Node(start_row, start_col));
	memset(d, -1, sizeof(d));
	d[start_row][start_col] = 0;
	while(!q.empty()) {
		Node cur = q.front();
		q.pop();
		if(cur.x == end_row && cur.y == end_col) return ;   //要这样写，这样写起点和终点一样的话还是没问题
		for(int i = 0; i < 8; ++i) {
			int cur_row = cur.x + row_change[i], cur_col = cur.y + col_change[i];
			if(is_inbound(cur_row, cur_col) && d[cur_row][cur_col] < 1) {
				d[cur_row][cur_col] = d[cur.x][cur.y] + 1;
				/*
				if(cur_row == end_row && cur_col == end_col) {   //如果这样判断，是否到达了终点，如果终点和起点不一样，这个是可以的，可是如果终点和起点一样，将得到错误的答案。
					return ;
				}
				*/
				q.push(Node(cur_row, cur_col));
			}
		}
	}
}


int main() {
	char begin[10], end[10];
	while(scanf("%s%s", begin, end) == 2) {
		analy_input(begin, end);
		//printf("sb %d se %d eb %d ee %d\n", start_row, start_col, end_row, end_col);
		bfs();
		printf("To get from %s to %s takes %d knight moves.\n", begin, end, d[end_row][end_col]);

	}
	return 0;
}