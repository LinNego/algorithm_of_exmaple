#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 1000 + 1;
int maxi[maxn], mini[maxn];
int a[maxn], n;
bool vis[maxn];
int dp_maxi(int s) {
	int &ans = maxi[s];
	if(s == 0) return ans = 0;
	if(ans != -1) 
		return ans;
	ans = 1 << 31;
	for(int i = 1; i <= n; ++i) {
		if(s >= a[i]) {
			ans = max(ans, dp_maxi(s - a[i]) + 1);
		}
	}
	return ans;
}

int dp_mini(int s) {
	if(s == 0) return 0;
	int &ans = mini[s];
	if(vis[s]) return ans;
	ans = ~(1 << 31);
	for(int i = 1; i <= n; ++i) {
		if(s >= a[i]) {
			ans = min(ans, dp_mini(s - a[i]) + 1);
		}
	}
	vis[s] = 1;
	return ans;
}
void print_ans_mini1(int s) {
	/* 字典序最大 */
	for(int i = n; i >= 1; --i) {
		if(s >= a[i] && mini[s] == mini[s - a[i]] + 1) {
			printf("%d ", i); 
			print_ans_mini1(s - a[i]); 
		} 
	}  
} 
void print_ans_mini2(int s) {
	for(int i = 1; i <= n; ++i) {
		if(s >= a[i] && mini[s] == mini[s - a[i]] + 1) {
			printf("%d ", i); 
			print_ans_mini2(s - a[i]); 
		} 
	} 
} 
int main() {
	int s; 
	cin >> n >> s; 
	for(int i = 1; i <= n; ++i) {
		cin >> a[i]; 
	} 
	memset(maxi, -1, sizeof(maxi)); 
	memset(vis, 0, sizeof(vis)); 
	//dp_maxi(s); 
//	cout << maxi[s] << endl; 
	dp_mini(s); 
	for(int i = 1; i <= s; ++i) {
		cout << mini[i] << " ";
	}
	cout << endl;
//	cout< mini[s] << endl; 
	print_ans_mini2(s);
	printf("\n");
	return 0; 
}