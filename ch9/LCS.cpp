//LCS.cpp 

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1000;
int d[maxn][maxn];
int a[maxn], b[maxn];
int dp(int i, int j) {
	if(d[i][j] >= 0) return d[i][j];	
	int &ans = d[i][j];
	if(a[i] == b[j]) ans = dp(i - 1, j - 1) + 1;
	else ans = max(dp(i - 1, j), dp(i, j - 1));
	return ans;
}

int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for(int i = 1; i <= m; ++i) {
		cin >> b[i];
	}
	memset(d, -1, sizeof(d));
	for(int j = 0; j <= m; ++j) {
		d[0][j] = 0;
	}
	for(int i = 0; i <= n; ++i) {
		d[i][0] = 0;
	}
	cout << dp(n, m) << endl;
	return 0;
}