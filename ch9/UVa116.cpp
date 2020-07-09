#include <iostream>
#include <cstring>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::sort;

const int maxm = 15;
const int maxn = 105;
const int inf = 1000000000;

int matrix[maxm][maxn];
int d[maxm][maxn], next[maxm][maxn];

int main() {
	int m, n;
	while(cin >> m >> n) {
		memset(matrix, 0, sizeof(matrix));
		for(int i = 1; i <= m; ++i) {
			for(int j = 1; j <= n; ++j) {
				cin >> matrix[i][j];
			}
		}
		for(int i = 1; i <= m; ++i) {
			d[i][n] = matrix[i][n];
		}
		int ans = inf, first;
		for(int j = n - 1; j >= 1; --j) {
			for(int i = 1; i <= m; ++i) {
				int row[3] = {i - 1, i, i + 1};
				if(i == m) row[2] = 1;
				if(i == 1) row[0] = m;
				sort(row, row + 3);
				d[i][j] = inf;
				//if(j == 1) cout << d[i][j] << " ";
				for(int k = 0; k < 3; ++k) {
					int v = d[row[k]][j + 1] + matrix[i][j];
					if(v < d[i][j]) {
						d[i][j] = v;
						next[i][j] = row[k];
						//cout << "i : " << i << " j : " << j << " row: " << row[k] << endl;
					}
				}
				//if(j == 1) cout << d[i][j] << endl;
				/*
				if(j == 1 && d[i][j] < ans) {
					first = i;
					ans = d[i][j];
				}
				*/
			}
		}
		for(int i = 1; i <= m; ++i) {
			if(d[i][1] < ans) {
				ans = d[i][1];
				first = i;
			}
		}
		printf("%d", first);
		int i = next[first][1];
		for(int j = 2; j <= n; ++j) {
			printf(" %d", i);
			i = next[i][j];
		}
		printf("\n%d\n", ans);
	}
	return 0;
}