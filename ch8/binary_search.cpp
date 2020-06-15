//binary_search.cpp
#include <cstdio>

int binary_search(int *A, int a, int b, int ans) {
	while(a <= b)  {
		int m = a + (b - a) / 2;
		if(A[m] == ans) {
			//hhprintf("%d", ans);
			return m;
		}
		else if(A[m] < ans) {
			//printf("A[m]2:%d\n", A[m]);
			a = m + 1;
		}
		else {
			//printf("A[m]:3%d\n", A[m]);
			b = m - 1;
		}
	}
	return -1;
}

int main() {
	int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int ans;
	if((ans = binary_search(A, 0, 9, 3)) != -1) {
		printf("%d\n", ans);
	}
	else {
		printf("no");
	}
	return 0;
}