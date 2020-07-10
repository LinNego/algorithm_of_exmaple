#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 105;
const int inf = 1000000000;
int d[maxn];
vector<int> weight, value;
int n, w;
/*递归*/
int dp(int cur) {
	int &ans = d[cur];
	if(ans != -1) return ans;
	ans = -inf;
	for(int i = 0; i < n; ++i) {
		if(cur >= weight[i]) {
			ans = max(ans, dp(cur - weight[i]) + value[i]);
			if(ans < 0) ans = -inf;
		}
	}
	return ans;
}

/*迭代*/
int max_path[maxn];
int sol() {
	d[0] = 0;
	for(int i = 1; i <= w; ++i) {
		d[i] = -inf;
		for(int j = 0; j < n; ++j) {
			if(i >= weight[j]) {
				if(d[i] > d[i - weight[j]] + value[j]) {
					d[i] = d[i - weight[j]] + value[j];
					max_path[i] = j;
				}
			}
		}
	}	
	return d[w];
}
/*写出最长路*/
void print_ans(int S) {
	for(int i = 0; i < n; ++i) {
		if(S - weight[i] >= 0 && d[S] == d[S - weight[i]] + value[i]) {
			printf("%d ", i);
			print_ans(S - weight[i]);
			break;
		}
	}
}

void print_ans1(int S) {
	while(S != 0) {
		printf("%d ", max_path[S]);
		S -= weight[max_path[S]];
	}
}

int main() {
	int kase = 0;
	while(cin >> n >> w && n) {
		weight.clear();
		value.clear();
		memset(d, -1, sizeof(d));
		d[0] = 0;
		int temp = 0;
		for(int i = 0; i < n; ++i) {
			cin >> temp;
			weight.push_back(temp);				
		}
		for(int i = 0; i < n; ++i) {
			cin >> temp;
			value.push_back(temp);
		}
		int ans = sol();
		if(ans < 0) cout << -1 << endl;
		else cout << ans << endl;
		print_ans(w);
		cout << endl;
	}
}
