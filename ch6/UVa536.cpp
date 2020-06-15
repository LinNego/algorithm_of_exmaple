//UVa536.cpp
//Greatljc

#include <cstdio>
#include <cstring>
#include <cstdlib>

const int maxn = 30;
const int max_node = 30000;

char preord[maxn];
char inord[maxn];
char postord[maxn]; 

int root;
int lch[max_node], rch[max_node];
char value[max_node];
int build_tree(int &p, int b, int e) {
	int croot = p;
	//printf("p: %d", p);
	for(int i = b; i < e; ++i) {
		if(preord[p] == inord[i]) {
		//	value[croot] = inord[i];
			if(i - b > 0) lch[croot] = build_tree(++p, b, i);
			if(e - i - 1 > 0) rch[croot] = build_tree(++p, i + 1, e);
			printf("%c", inord[i]);
			return croot;
		}
	}
}

int dfs(int cur) {
	if(lch[cur] != 0) dfs(lch[cur]);
	if(rch[cur] != 0) dfs(rch[cur]);
	printf("%c", value[cur]);
}

int main() {
	while(scanf("%s%s", preord, inord) == 2) {
	//	printf("%s\n", preord);
	//	printf("%s\n", inord);
		int len = strlen(inord);
		int num = 0;
		memset(lch, 0, sizeof(lch));
		memset(rch, 0, sizeof(rch));
		memset(value, 0, sizeof(value));
		root = build_tree(num, 0, len);
		//dfs(root);
		printf("\n");
	}
	return 0;
}