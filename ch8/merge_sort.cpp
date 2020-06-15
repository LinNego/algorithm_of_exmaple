//merge_sort.cpp
#include <iostream>
using namespace std;
const int maxn = 100;
int cnt = 0;
void merge_sort(int *A, int x, int y, int *T) {
	if(y - x > 1) {
		int m = x + (y - x) / 2;
		merge_sort(A, x, m);
		merge_sort(A, m, y);
		int p = x, q = m, i = x;
		while(p < m || q < y) {   //假设限定死条件，就是要只要有一个序列非空就继续合并
			if(q >= y || (p < m && A[p] < A[q])) {
				T[i++] = A[p++];
			}
			else {
				T[i++] = A[q++];
				cnt += m - p;
			}
		}
		for(int i = x; i < y; ++i) {
			A[i] = T[i];
		}
	}
}
int main() {
	return 0;
}