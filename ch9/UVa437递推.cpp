#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;



const int maxn = 30;
int n, d[maxn][3], b[maxn][3];
void get_otherdimention(int &x, int &y, int i, int j) {
	for(int k = 0; k < 3; ++k) {
		if(k != j) x = k;
	}
	for(int k = 0; k < 3; ++k) {
		if(k != j && k != x) y = k;
	}
}

int main() {
	int kase = 0;
	while(cin >> n && n) {
		memset(d, -1, sizeof(d));
		for(int i = 0; i < n; ++i) {
			cin >> b[i][0] >> b[i][1] >> b[i][2];
			sort(b[i], b[i] + 3);
		}
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < 3; ++j) {
				d[i][j] = b[i][j];
			}
		}
		for()
	}
	return 0;
}