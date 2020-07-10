/*UVa12563.cpp*/
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

const int maxn = 55;
const int maxt = 180 * 50 + 678;

int d[maxn][maxt + 1];
int timess[maxn][maxt + 1];
bool cmp(int a, int b) {
	return a < b;
}
int main() {
	int T, n, t, kase = 0;
	cin >> T;
	int value[maxn];
	while(T--) {
		cin >> n >> t;
		for(int i = 1; i <= n; ++i) {
			cin >> value[i];
		}
		for(int j = 0; j <= t; ++j) {
			d[0][j]= 0;
			timess[0][j] = 0;
		}
		sort(value + 1, value + n + 1, cmp);
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j < t; ++j) {
				d[i][j] = d[i - 1][j];
				timess[i][j] = timess[i - 1][j];
				if(j >= value[i]) {
					if(d[i - 1][j - value[i]] + 1 > d[i][j]) {
						d[i][j] = d[i - 1][j - value[i]] + 1;
						timess[i][j] = timess[i - 1][j - value[i]] + value[i];
						//这样会导致只面向了更多的歌曲，比如还剩20.一首歌15，另外一首歌10，那么如果先是15，再10的话就会有问题
					}
					else if(d[i - 1][j - value[i]] + 1 == d[i][j] && timess[i][j] < timess[i - 1][j - value[i]] + value[i]) {
						timess[i][j] = timess[i - 1][j - value[i]] + value[i];
					} 
				}
			}
		}
		cout << "Case " << ++kase << ": " << d[n][t - 1] + 1;
		cout << " " <<  timess[n][t - 1] + 678 << endl;

	}
	cout << (double)clock() / CLOCKS_PER_SEC << endl;
	return 0;
}