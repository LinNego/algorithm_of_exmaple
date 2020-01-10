#include <iostream>
#include <cstdio>
#include <cstring>
const int maxn = 1000;
using namespace std;
typedef struct 
{
	int row;
	int col;	
} matrix;
typedef int graph[100][100];
void test_graph(graph g, int n)
{
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			printf("%d ", g[i][j]);
		}
		printf("\n");
	}
}
int d[maxn];

int dp(graph g, int s, int n)
{
	int &ans = d[s];
	if(ans > 0) return d[s];
	ans = 1;
	for(int i = 0; i < n; ++i) {
		if(g[s][i]) {
			ans = max(ans, dp(g, i, n) + 1);
		}
	}
	return ans;
}
void print_ans(graph g, int n, int i) {
	//test_graph(g, n);
	printf("%d ", i);
	for(int j = 0; j < n; ++j) {
		if(g[i][j] && d[i] == d[j] + 1) {
			print_ans(g, n, j);
			//printf("?????\n");
			break;
		}
	}
}
int main() 
{
	int N;
	cin >> N;
	while (N > 0) {
		int n, a, b;
		cin >> n;
		graph g;
		matrix m[maxn];
		memset(g, 0, sizeof(g));
		for (int i = 0; i < n; ++i) {
			cin >> a >> b;
			m[i].row = a;
			m[i].col = b;
		}
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				bool sign = ((m[i].row < m[j].row && m[i].col < m[j].col) || (m[i].col < m[j].row && m[i].row < m[j].col));
					if(sign) {
						g[i][j] = 1;
					}
			}
		}
		//test_graph(G, n);
		memset(d, 0, sizeof(d));
		int max = 1 << 31, max_index;
		for(int i = 0; i < n; ++i) {
			int temp = dp(g, i, n);
			if(max < temp) {
				max = temp; 
				max_index = i;
			}
		}
		for(int i = 0; i < n; ++i) {
			printf("%d ", d[i]);
		}
		printf("\n");
		printf("%d %d %d\n", max, max_index, d[max_index]);
		//test_graph(G, n);
		print_ans(g, n, max_index);
		--N;
	}
	return 0;
}