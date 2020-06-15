//UVa12657.cpp
//Grealjc

#include <cstdio>
#include <cstring>
const int maxn = 100005;
int left[maxn], right[maxn]; //下标为i的左节点和右节点的标号
void link(int l, int r) {
	right[l] = r;
	left[r] = l;
}
void ini_list(int n) {
	for(int i = 1; i <= n; ++i) {
		if(i == 1) left[i] = 0;
		else left[i] = i - 1;
		if(i == n) right[i] = 0;
		else right[i] = i + 1;
	}
	left[0] = n;
	right[0] = 1;
}
long long print(int reverse, long long &ans) {
	int b;
	if(reverse) {
		b = left[0];
		int i = 1;
		while(b != 0) {
			if(i % 2 == 1) {
				ans += b;
			}
			++i;
			b = left[b];
		}
	}
	else {
		b = right[0];
		int i = 1;
		while(b != 0) {
			if(i % 2 == 1) {
				ans += b;
			}
			++i;
			b = right[b];
		}
	}
	return ans;
}
void output(int reverse) {
	int b;
	if(reverse) {
		b = left[0];
		int i = 1;
		printf("%d ", b);
		while(b != 0) {
			b = left[b];
			printf("%d ", b);
		}
	}
	else {
		b = right[0];
		int i = 1;
		printf("%d ", b);
		while(b != 0) {
			b = right[b];
			printf("%d ", b);
		}
	}
	printf("\n");
}
int main() {
	int n, m, kase = 1;
	while(scanf("%d %d", &n, &m) != EOF) {
		long long ans = 0;
		ini_list(n);

		int cmd, x, y, reverse = 0;
		for(int i = 0; i < m; ++i) {	
			scanf("%d", &cmd);
			if(cmd == 4) {
				reverse = !reverse;
				continue;
			}
			else {
				scanf("%d %d", &x, &y);
			}
			if(cmd == 3) {    //x和y本身相邻这种情况没有考虑到
				if(right[y] == x) {
					link(y, right[x]);
					link(left[y], x);
					link(x, y);
				}
				else if(right[x] == y) {
					link(x, right[y]);
					link(left[x], y);
					link(y, x);
				}	
				else {
					int l = left[y], r = right[y];
					link(left[x], y);
					link(y, right[x]);
					link(l, x);
					link(x, r);
				}
				//output(reverse);
				continue;
			}
			
			if(reverse && (cmd == 1 || cmd == 2)) {
				cmd = 3 - cmd;
			}	
			if(cmd == 1){
				if(right[x] == y) continue;
				link(left[x], right[x]);
				link(left[y], x);
				link(x, y);
			}
			else {
				if(right[y] == x) continue;
				link(left[x], right[x]);
				link(x, right[y]);
				link(y, x);
			}
			//output(reverse);
		}
		print(reverse, ans);
		printf("Case %ld: %lld\n", kase++, ans);
	}
	return 0;
}