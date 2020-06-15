//quick_sort.cpp
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstring>
using namespace std;
void quick_sort(int *A, int p, int q) {
	if(p < q) {
		int c = A[p], in = p;
		for(int i = p + 1; i <= q; ++i) {
			if(A[i] <= c) {
				++in;
				swap(A[in], A[i]);
			}
		}
		swap(A[in], A[p]);
		
		for(int i = 0; i < 3; ++i) {
			cout << A[i] << ' ';
		}
		cout << endl;

	//	quick_sort(A, p, in - 1);
	//	quick_sort(A, in + 1, q);

		//quick_sort(A, in + 1, q);
	}
}

int quick_sort2(int *A, int p, int q, int k) {
	if(p < q) {
		int piv = A[q], in = p - 1;
		//cout << "piv" << piv << " "<< "in" << in << endl;
		for(int i = p; i < q; ++i) {
			if(A[i] <= piv) {
				in += 1;
				swap(A[i], A[in]);
			}
		}
		swap(A[in + 1], A[q]);
		
		int len = in - p + 1;
		//cout << "len" << len << " " << "in" << in << " " << "k" << k << endl;
		if(len + 1 == k) {
			//cout << "piv" << piv <<  endl;
			return piv;
		}
		else if(k <= len) {
			return quick_sort2(A, p, in, k);
		}
		else {
			//cout << "right" << endl;
			k = k - (len + 1);
			return quick_sort2(A, in + 2, q, k);
		}
		
		//quick_sort2(A, p, in);
		//quick_sort2(A, in + 2, q);
	}
	/*
	 *没加else真的是太乌龙了。
	 *第k个要不就是在序列个数不为1的，要不就是序列为1那个元素
	 */
	else {
		return A[p];
	}

}
int quick_choose(int *A, int p, int q, int k) {
	if(p < q) {
		int c = A[p], in = p;
		for(int i = p + 1; i <= q; ++i) {
			if(A[i] <= c) {
				++in;
				swap(A[in], A[i]);
			}
		}
		swap(A[in], A[p]); 
		int len = in - p;
		if(k == len + 1) return c;
		else if(k <= len) {
			return quick_choose(A, p, in - 1, k);
		}
		else {
			k -= (len + 1);
			return quick_choose(A, in + 1, q, k);
		}
		/*
		for(int i = 0; i < 9; ++i) {
			cout << A[i] << ' ';
		cout << endl;
		*/
		/*
		if(in == k - 1) return A[k - 1];
		else if(in - p + tol > k) {
			quick_choose(A, p, in - 1, k, tol);
		}
		else {
			tol += (in - p + 1);
			quick_choose(A, in + 1, q, k, tol);
		}
		*/
	}
	else {
		return A[p];
	}
}
void print(int *A, int n) {
	for(int i = 0; i < n; ++i) {
		cout << A[i] << ' ';
	}
	cout << endl;
}
int main() {
	int A[10] = {61, 61, 61, 61, 51, 52, 53, 54, 55, 56};
	print(A, 10);
	cout << quick_choose(A, 0, 9, 1) << endl;
	print(A, 10);
	
	/*
	for(int i = 0; i < 10; ++i) {
		srand(i);
		for(int j = 0; j < 10; ++j) {
			A[j] = rand();
		}
		//quick_sort2(A, 0, 9);
		cout << quick_choose(A, 0, 9, 3) << endl;
		print(A, 10);
	}
	
	*/
	
	for(int i = 0; i < 10; ++i) {
		memset(A, 0, sizeof(A));
		for(int j = 0; j < 10; ++j) {
			cin >> A[j];
		}
		cout << quick_choose(A, 0, 9, 10) << endl;
		print(A, 10);
	}
	
//	quick_sort(A, 0, 2);
	//print(A, 3);	
	cout << endl;
	return 0;
}