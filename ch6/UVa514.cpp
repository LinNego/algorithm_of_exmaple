//UVa514.cpp
//Greatljc

#include <cstdio>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;
int trains[1005];
stack<int> sta;
void TestInput(int n) {
	for(int i = 0; i < n; ++i) {
		printf("%d ", trains[i]);
	}
	printf("\n");
}
void Stack_Clear(stack<int> &s) {
	stack<int> e;
	swap(e, s);
}
int main() {
	int n;
	while(scanf("%d", &n) != EOF && n != 0) {
		int k = 0;
		while(scanf("%d", &trains[k]) && trains[k] != 0) {
			//sta.clear();
			for(k = 1; k < n; ++k) {
				scanf("%d", &trains[k]);
			}
			k = 0;
			//TestInput(n);
			int A = 0, B = 1;
			int ok = 1;
			while(B <= n) {
				//printf("A:%ds", A);
				if(!sta.empty() && sta.top() == trains[A]) {
					//printf("why");
					++A;
					sta.pop();
				}
				else if(B == trains[A]) {
					//printf("????");
					++B;
					++A;
				}
				else {
					sta.push(B++);
				}
				//printf("A:%de", A);

			}
			//printf("A:%d", A);
			while(!sta.empty()) {
				if(sta.top() != trains[A]) break;
				else {
					++A;
					sta.pop();
				}
			}
			printf("%s\n", A == n ? "Yes": "No");
			Stack_Clear(sta);
		}	
		printf("\n");
	}
	return 0;	
}