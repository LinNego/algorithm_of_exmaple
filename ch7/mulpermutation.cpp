//mulpermutation.cpp
//LinNego
#include <cstdio>
using namespace std;

int n;
void mulpermutation(int cur, int *P, int *A) {
	if(cur == n) {
		for(int i = 0; i < n; ++i) {
			printf("%d ", A[i]);
		}
		printf("\n");
		return ;
	}
	for(int i = 0; i < n; ++i) {
		if(!i || P[i - 1] != P[i]) {
			int c1 = 0, c2 = 0;
			for(int j = 0; j < cur; ++j) if(A[j] == P[i]) ++c1;
			for(int j = 0; j < n; ++j) if(P[i] == P[j]) ++c2;
			if(c1 < c2) {
				A[cur] = P[i];
				mulpermutation(cur + 1, P, A);
			}
		}
	}
}

int main() {
	int P[5] = {1, 1, 2, 3, 4};
	int A[5];
	n = 5;
	mulpermutation(0, P, A);
	return 0;
}