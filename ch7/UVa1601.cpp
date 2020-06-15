//Greatljc
//UVa1601.cpp

#include <cstdio>
#include <queue>
#include <cctype>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 20;
const int maxs = 150;

struct Node {
	int a, b, c;
	Node(int a, int b, int c):a(a), b(b), c(c) {}
};



char maze[maxn][maxn];
int G[maxs][5];
int deg[maxs];
int s[3], e[3];

int dx[5] = {0, 0, -1, 0, 1};
int dy[5] = {0, -1, 0, 1, 0};

int d[maxs][maxs][maxs];

/*
inline bool conflict(int a, int b, int a2, int b2) {
	return a2 == b2 || (a2 == b && b2 == a);
}
*/
inline bool conflict(int a, int b) {
	return a == b;
}

int bfs() {
	queue<Node> q;
	q.push(Node(s[0], s[1], s[2]));
	memset(d, -1, sizeof(d));
	d[s[0]][s[1]][s[2]] = 0;
	while(!q.empty()) {
		Node u = q.front();
		q.pop();
		int a = u.a, b = u.b, c = u.c;
		if(a == e[0] && b == e[1] && c == e[2]) return d[a][b][c];
		for(int i = 0; i < deg[a]; ++i) {
			int a2 = G[a][i];
			//if(conflict(a2, b)) continue;    //这里是有逻辑上的问题的，他们是同时移动的，并不能这样判断条件。
			//if(conflict(a2, c)) continue;
			for(int j = 0; j < deg[b]; ++j) {
				int b2 = G[b][j];
				//if(conflict(a, b, a2, b2)) continue;
				if(conflict(b2, a2)) continue;
				if(conflict(b, a2) && conflict(a, b2)) continue;
				for(int k = 0; k < deg[c]; ++k) {
					int c2 = G[c][k];
				//	if(conflict(a, c, a2, c2)) continue;
				//	if(conflict(b, c, b2, c2)) continue;
					if(conflict(a2, c2) || conflict(b2, c2)) continue;
					if((conflict(a2, c) && conflict(c2, a)) || (conflict(b2, c)) && conflict(c2, b)) continue;
					if(d[a2][b2][c2] < 0) {
						d[a2][b2][c2] = d[a][b][c] + 1;
						q.push(Node(a2, b2, c2));
					}
				}
			}
		}
	}
	return -1;
}


int main() {
	int w, h, n;
	while(scanf("%d %d %d", &w, &h, &n) != EOF && n) {
		getchar();
		for(int i = 0; i < h; ++i) {
			fgets(maze[i], 20, stdin);
		}
		int cnt, x[maxs], y[maxs], id[maxs][maxs];
		cnt = 0;
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		memset(id, 0, sizeof(id));
		for(int i = 0; i < h; ++i) {
			for(int j = 0; j < w; ++j) {
				if(maze[i][j] != '#') {
					x[cnt] = i;
					y[cnt] = j;
					id[i][j] = cnt;
					if(isupper(maze[i][j])) 
						e[maze[i][j] - 'A'] = cnt;
					else if(islower(maze[i][j])) 
						s[maze[i][j] - 'a'] = cnt;
					++cnt;
				}
			}
		}
		for(int i = 0; i < cnt; ++i) {
			deg[i] = 0;
			for(int j = 0; j < 5; ++j) {
				int nx = x[i] + dx[j];
				int ny = y[i] + dy[j];
				if(maze[nx][ny] != '#') {
					G[i][deg[i]++] = id[nx][ny];	
				}
			}
		}
		if(n <= 2) { deg[cnt] = 1; G[cnt][0] = cnt; s[2] = e[2] = cnt++;}  //如果是==而不是<=,那么如果n == 1， 代码就要更长。
		if(n <= 1) { deg[cnt] = 1; G[cnt][0] = cnt; s[1] = e[1] = cnt++;}
		printf("%d\n", bfs());
		
	}
	return 0;
}