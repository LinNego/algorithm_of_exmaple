//子集生成.cpp
//LinNego

#include <cstdio>
#include <cstring>

int n;

//好像前提就是枚举0~n-1，并不是下标，所以加一个参数int *P行不通
void print_subset(int cur, int *A, int *P ) {
	for(int i = 0; i < cur; ++i) printf("%d", A[i]);
	printf("\n");
	int s = cur ? A[cur - 1] + 1: 0;  //为了定序，不让(1, 2) 和 (2, 1)这样的集合枚举两次。
	for(int i = s; i < n; ++i) {
		A[cur] = P[i];
		print_subset(cur + 1, P, A);
	}	
}

void print_subset2(int cur, int *A, int *P) {
	if(cur == n) {
		for(int i = 0; i < n; ++i) {
			if(A[i]) printf("%d ", P[i]);
		}
		printf("\n");
		return ;
	}
	A[cur] = 1;
	print_subset2(cur + 1, A, P);
	A[cur] = 0;
	print_subset2(cur + 1, A, P);
}

void print_subset3(int n, int s, int *P) {
	for(int i = 0; i < n; ++i) {
		if(s & (1 << i)) printf("%d ", P[i]);
	}
	printf("\n");
}

void help(int *P) {
	for(int i = 0; i < (1 << n); ++i) {
		print_subset3(n, i, P);
	}
}

int main() {
	int P[5] = {66, 2, 31, 2, 5};
	int A[5];
	n = 5;
	memset(A, 0, sizeof(A));
	//print_subset3(0, A, P);
	help(P);
	return 0;
}