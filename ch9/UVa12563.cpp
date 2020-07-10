/*UVa12563.cpp*/
#include <iostream>
using namespace std;

const int maxn = 50;
const int maxt = 180 * 50 + 678;

int d[maxn][maxt + 1];
int book[maxn][maxt + 1];
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
			d[0][j]= -1;
			//book[0][j] = 0;
		}
		d[0][0] = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j < t; ++j) {
				d[i][j] = d[i - 1][j];
				//book[i][j] = book[i - 1][j];
				if(j >= value[i]) {
					if(d[i - 1][j - value[i]] + value[i] > d[i][j]) {
						//book[i][j] = book[i - 1][j - value[i]] + 1;
						d[i][j] = d[i - 1][j - value[i]] + value[i];
						//cout << i << " " << j << " " << book[i][j] << " " << endl;
						//cout << i << " " << j << " " << d[i][j] << endl;
					}
				}
			}
		}
		cout << "Case " << ++kase << ": " << book[n][t - 1] + 1;
		cout << " " <<  d[n][t - 1] + 678 << endl;

	}
	return 0;
}