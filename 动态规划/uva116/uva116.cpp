/*
 * d(i, j) = max( d(i + 1, j) + a[i][j], d(i + 1, j + 1) + a[i][j], d(i - 1, j - 1) + a[i][j]);
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = ~(1 << 31);
int m, n;
int matrix[15][105], d[15][105], s[105];
bool vis[15][105];
void change_xy(int &i, int &j) {
	if(i > m) 
		i = 1;
	if(i < 1)
		i = m;
	if(j > n)
		j = 1;
	if(j < 1)
		j = n;
}
int dp(int i, int j) {
	change_xy(i, j);
	cout << "i " << i << "j " << j << endl; 
	int ans = inf, t = matrix[i][j];
	if(j == n) return matrix[i][j];
	if(vis[i][j]) return d[i][j];
	ans = min(ans, dp(i, j + 1));
	cout << ans << endl;
	ans = min(ans, dp(i + 1, j + 1));
	cout << ans << endl;
	ans = min(ans, dp(i - 1, j + 1));
	cout << ans << endl;
	vis[i][j] = 1;
	return d[i][j] = ans + matrix[i][j];
}
void print_ans(int i, int j) {
	if(i > 6) return ;
	printf("%d ", i);
	
}
int main() {
	while(cin >> m >> n) {
		for(int i = 1; i <= m; ++i) {
			for(int j = 1 ; j <= n; ++j) {
				cin >> matrix[i][j];
				d[i][j] = matrix[i][j];
			}
		}
		memset(vis, 0, sizeof(vis));
		int ans = inf, index;
		
		for(int j = 1; j <= n; ++j) {
			if(ans > dp(j, 1)) {
				index = j;
			}
		}
		
		//ans = dp(1, 1);
		cout << ans << endl;
		for(int i = 1; i <= n; ++i) {
			printf("%d ", j);
			//找到最小的，然后比较 右上，右，右下哪个最小

		}
		cout << ans << endl;
	}
}