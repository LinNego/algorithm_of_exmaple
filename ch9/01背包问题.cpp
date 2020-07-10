/*01背包问题*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 105;

int d[maxn][maxn];
int n, v;
vector<int> volume(maxn), weight(maxn);

/*迭代*/
int sol() {
	for(int j = 0; j <= v; ++j) {
		d[n][j] = 0;
	}
	for(int i = n - 1; i >= 0; --i) {
		for(int j = 0; j <= v; ++j) {
			d[i][j] = d[i + 1][j];
			if(j >= volume[i])
				d[i][j] = max(d[i][j], d[i + 1][j - volume[i]] + weight[i]);	
			/*下面的代码错误的：因为状态转移是d[i][j] = max(d[i + 1][j], d[i + 1][j - volume[i]] + weight[i]); */
			/*max的d[i + 1][j]并不需要j >= volume[i] */
			/*
			if(j >= volume[i]) 
				d[i][j] = max(d[i + 1][j], d[i + 1][j - volume[i]] + weight[i]);
				*/
		}
	}
	return d[0][v];
}

void print(int i, int S) {
	for(int i = 0; i < n; ++i) {
		if(S - volume[i] >= 0 && d[i][S] == d[i + 1][S - volume[i]] + weight[i]) 
			printf("%d ", i);
			print(i + 1, S - volume[i]);
	}
}

int main() {
	int kase = 0;
	while(cin >> n >> v && n) {
		volume.clear();
		weight.clear();
		for(int i = 0; i < n; ++i) {
			cin >> volume[i] >> weight[i];
		}
		cout << sol() << endl;
	}
}