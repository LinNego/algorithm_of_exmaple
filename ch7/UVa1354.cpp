//UVa1354.cpp
//LinNego

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct Tree {
	double L, R;
	Tree(): L(0), R(0) { }
};
const int maxn = 6;

double w[maxn], sum[1 << maxn], r;
int vis[1 << maxn];
int n;
//int r;
vector<Tree> tree[1 << maxn];

void dfs(int subset) {
	if(vis[subset]) return ;
	vis[subset] = true;

	bool have_child = 0;
	//之所以需要 &subset 而不是直接left - 1，因为并不是全集出来的。
	//考虑 11100111，经过减之后，如果不&，那么会出现 11111000...这些情况，很明显中间的两个0师妹元素的，现在有了元素。
	for(int left = (subset - 1) & subset; left; left = (left - 1) & subset) {
		have_child = 1;

		int right = subset ^ left;
	//	printf("left: %d right %d\n", left, right);
	//	printf("sum[right]:%lf sum[left]:%lf, sum[subset]:%lf\n", sum[right])
		double d1 = sum[right] / sum[subset];
		double d2 = sum[left] / sum[subset];
	//	printf("d1:%lf d2:%lf \n", d1, d2);

		dfs(left);
		dfs(right);

		for(int i = 0; i < tree[left].size(); ++i) {
			for(int j = 0; j < tree[right].size(); ++j) {
				/*
				Tree tr;
				tr.L = max(tree[left][i].L + d1, tree[right][j].L - d2);
				tr.R = max(tree[right][j].R + d2, tree[left][i].R - d1);
				//这个节点有一个错误的思路，想要找到最大的L,R再push_back，而不是找到一个就push_back一个.
				//之所以每一个可能的值都push_back,我想有一个原因是如果每次都选大的，不能保证上层二叉树的宽度还小于width。
				if(tr.L + tr.R < r) tree[subset].push_back(tr);
				*/
		        Tree t;
		        t.L = max(tree[left][i].L + d1, tree[jjright][j].L - d2);
		        t.R = max(tree[right][j].R + d2, tree[left][i].R - d1);
	//	        printf("%lf %lf\n", t.L, t.R);
		        if(t.L + t.R < r) tree[subset].push_back(t);
			}
		}
	}
	if(!have_child) tree[subset].push_back(Tree());
}

int main() {
	//int n;
	//scanf("%d", &n);
	int T;
	scanf("%d", &T);
	while(T--) {
	//for(int i = 0; i < T; ++i) {
		scanf("%lf%d", &r, &n);
		for(int i = 0; i < n; ++i) {
			scanf("%lf", &w[i]);
		}
		for(int i = 0; i < (1 << n); ++i) {
			tree[i].clear();
			sum[i] = 0;
			for(int j = 0; j < n; ++j) {
				if(i & (1 << j)) sum[i] += w[j];
			}
		}
	

		int root = (1 << n) - 1;
		memset(vis, 0, sizeof(vis));
		dfs(root);
		double ans = -1;
		for(int i = 0; i < tree[root].size(); ++i) {
			ans = max(ans, tree[root][i].L + tree[root][i].R);
		}
		//if(ans + 1 <= 1e-5) printf("-1\n");
		printf("%.10lf\n", ans);
	}
	return 0;	
}




int mod(int a, int b) {
	return b == 0 ? a: mod(b, a % b);
}