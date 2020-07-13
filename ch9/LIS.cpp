//包含了DP解法，O(n ^ 2)
//LIS.cpp 最长上升子序列问题
//LinNego
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100000000;

int num[maxn], d[maxn], nexts[maxn];

int dp(int n) {
	int ans = 1, index = 0;
	/* i结束不好打印
	for(int i = 0; i < n; ++i) {
		d[i] = 1;
		for(int j = 0; j < i; ++j) {
			if(num[j] < num[i]) {
				d[i] = max(d[i], d[j] + 1);
			}
		}
		ans = max(ans, d[i]);
	}
	*/ //这样不好打印
	for(int i = n - 1; i >= 0; --i) {
		d[i] = 1;
		for(int j = i + 1; j < n; ++j) {
			if(num[i] < num[j]) {
				if(d[i] <= d[j] + 1) {
					d[i] = d[j] + 1;
					nexts[i] = j;
				}
				//cout << d[i] << endl;
				if(i == 0) cout << nexts[i] << endl;
			}
		}
		if(ans < d[i]) {
			ans = d[i];
			index = i;
		}
	}
	printf("%d ", index);
	for(int i = 1; i < ans; ++i) {
		index = nexts[index];
		printf("%d ", index);
	}
	printf("\n");

	return ans;
}
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	cout << dp(n) << endl;
	return 0;
}