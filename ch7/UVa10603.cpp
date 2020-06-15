//UVa10603.cpp
//Greatljc

#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>
using namespace std;

const int maxn = 201;

struct Node {
	int v[3], dist;
	int fa;
	Node(int dist = 0) :dist(dist) { }
	bool operator<(const Node &node) const {
		return dist > node.dist;	
	}
};

int visit[maxn][maxn];
int ans[maxn];
int cap[3];
//Node dis[maxn * maxn];
Node fla[maxn];
Node last;
Node par[maxn][maxn];
void update_ans(const Node &n) {
	for(int i = 0; i < 3; ++i) {
		int d = n.v[i];
		if(ans[d] < 0 || n.dist < ans[d]) {
			ans[d] = n.dist; 
			fla[d] = n;
			//printf("%d \n", ans[d]);
		}
	}
}

void solve(int a, int b, int c, int d) {
	cap[0] = a; cap[1] = b; cap[2] = c;
	Node start;
	start.dist = 0;
	start.v[0] = 0; start.v[1] = 0; start.v[2] = c; start.fa = -1;
	priority_queue<Node> q;
	visit[0][0] = 1;
	q.push(start);
	int cur = 0;
	par[0][0] = Node(-1);
	Node end;
	while(!q.empty()) {
		Node u = q.top();
		q.pop();
		update_ans(u);
		//int tcur = cur;
		//++cur;
		if(ans[d] >= 0) {
			break;
		}
		for(int i = 0; i < 3; ++i) {
			for(int j = 0; j < 3; ++j) {
				if(i != j) {
					if(u.v[i] == 0 || u.v[j] == cap[j]) continue;
			//		int mount = min(u.v[i], cap[j] - u.v[j]);
					int mount = min(cap[j], u.v[i] + u.v[j]) - u.v[j];
					Node v;
					memcpy(&v, &u, sizeof(u));
					v.v[i] -= mount;
					v.v[j] += mount;	
					v.dist = u.dist + mount;
					if(visit[v.v[0]][v.v[1]] < 0 || v.dist < visit[v.v[0]][v.v[1]]) {
						par[v.v[1]][v.v[2]] = u;
					//	v.fa = tcur;
						//dis[dcur] = v;
						visit[v.v[0]][v.v[1]] = v.dist;
						q.push(v);
					}
				}

			}
		}
	}
	while(d >= 0) {
		if(ans[d] >= 0) {
			last = fla[d];
			printf("%d %d\n", ans[d], d);
			break;
		}
		--d;
	}
	/*
	do {
		printf("%d %d %d\n", last.v[0], last.v[1], last.v[2]);
		last = dis[last.fa];
	} while(last.fa != -1);
	printf("%d %d %d\n", last.v[0], last.v[1], last.v[2]); //最开始的位置。
	*/

	do {
		printf("%d %d %d\n", last.v[0], last.v[1], last.v[2]);
		last = par[last.v[0]][last.v[1]];
	} while(last.dist != -1);

}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		memset(visit, -1, sizeof(visit));
		memset(ans, -1, sizeof(ans));
		//memset(dis, -1, sizeof(dis));
		solve(a, b, c, d);
	}
	return 0;
}