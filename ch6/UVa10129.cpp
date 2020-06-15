//UVa10129.cpp
//Greatljc

#include <cstdio>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

const int max_node = 26;
const int max_word = 100000 + 5;

struct edge {
	int u, v;
	edge(int u, int v): u(u), v(v) {}
};

int G[max_node][max_node];
int degrees[max_node][2];
int visit[max_node][max_node];
int cnt, ini_cnt;
int C[max_node];

void clear(stack<int> &node) {
	stack<int> temp;
	swap(temp, node);
}
void ini_graph(int n) {
	cnt = 0;
	ini_cnt = 0;
	memset(G, 0, sizeof(G));
	memset(degrees, 0, sizeof(degrees));
	memset(visit, 0, sizeof(visit));
	memset(C, 0, sizeof(C));
	char word[max_word];
	for(int i = 0; i < n; ++i) {
		scanf("%s", word);
		int len, u, v;
		len = strlen(word);
		u = word[0] - 'a';
		v = word[len - 1] - 'a';
		if(!C[u]) {
			ini_cnt += 1;
			C[u] = 1;
		}
		if(!C[v]) {
			ini_cnt += 1;
			C[v] = 1;
		}
		G[u][v] += 1;
		degrees[u][1] += 1;   //1 为出度
		degrees[v][0] += 1;   //0 为入度
	}
}

void is_connect(int u) {
	//memset(visit, 0, sizeof(visit));
	for(int v = 0; v < 26; ++v) {
		if(G[u][v] && !visit[u][v]) {
			visit[u][v] = 1;
			cnt += 1;
			is_connect(v);
			printf("%d %d\n", u, v);
		}
	}
}



int main() {
	int T;
	scanf("%d", &T);
	for(int i = 0; i < T; ++i) {
		int t;
		scanf("%d", &t);
		ini_graph(t);
		int n1 = 0, n2 = 0;
		int f1 = true, f2 = true;
		for(int j = 0; j < 26; ++j) {
			
			if(n1 > 1 || n2 > 1) {
				f1 = false; 
				break;
			}
			if(degrees[i][0] == degrees[i][1] + 1)  n1 += 1;
			else if(degrees[i][1] == degrees[i][0] + 1)  n2 += 1;
			else if(degrees[i][0] == degrees[i][1]) continue;
			else {
				f1 = false;
				break;
			}
		}
		/*
		for(int i = 0; i < 26; ++i) {
			for(int j = 0; j < 26; ++j) {
				if(G[i][j]) G[j][i] = G[i][j];
			}
		}
		*/
		is_connect(0);
		if(cnt < ini_cnt) {
			f2 = false;
		}
		if(f1 && f2) {
			printf("Orderng is possible.\n");
		}
		else {
			printf("The door cannot be opened.\n");
		}
	}
	return 0;
}