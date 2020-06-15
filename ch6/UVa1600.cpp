//UVa1600.cpp
//Greatljc

#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
struct Node {
	int x, y, k;
	Node(int x, int y, int k) : x(x), y(y), k(k) {}
};

const int maxn = 25;

int row_change[4] = {1, 0, -1, 0};  // 下，右， 上， 左
int col_change[4] = {0, 1, 0, -1};

int d[maxn][maxn][maxn];

int graph[maxn][maxn];
int m, n, k;

void read_input() {
	scanf("%d%d%d", &m, &n, &k);
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			scanf("%d", &graph[i][j]);
		}
	}
}

bool insigh(int x, int y) {
	return x >= 0 && x < m && y >= 0 && y < n;
}

void print() {

}

void solve() {
	queue<Node> q;
	q.push(Node(0, 0, 0));
	memset(d, -1, sizeof(d));
	d[0][0][0] = 0;
	while(!q.empty()) {
		Node cur = q.front();
		q.pop();
		if(cur.x == m - 1 && cur.y == n - 1) return ;
		for(int i = 0; i < 4; ++i) {
			int next_row = cur.x + row_change[i];
			int next_col = cur.y + col_change[i];
			Node next(next_row, next_col, cur.k);
			if(insigh(next_row, next_col)) {
				if(graph[next_row][next_col] == 1 && cur.k < k && d[next_row][next_col][cur.k + 1] < 0) {
					next.k = cur.k + 1;
					d[next_row][next_col][next.k] = d[cur.x][cur.y][cur.k] + 1;
					q.push(next);;
				}
				else if(graph[next_row][next_col] == 0 && d[next_row][next_col][0] < 0) {
					d[next_row][next_col][0] = d[cur.x][cur.y][cur.k] + 1;
					q.push(Node(next_row, next_col, 0));
				}
				
			}
		}

	}	
}



int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		read_input();
		solve();
		printf("%d\n", d[m - 1][n - 1][0]);
	}
	return 0;
}