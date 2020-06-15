#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int main() {
	stack<int> s;
	int n;
	while(cin >> n && n != 0){
		int m, target[MAXN];
		bool zero = 0;
		while(cin >> target[1] && target[1] != 0) {
			for(int i = 2; i <= n; ++i) {
				cin >> target[i];
			}
			int index = 1, num = 1;
			bool ok = true;
			for(int i = 1; i <= n; ++i) {
				printf("%d ", target[i]);
			}
			while(!s.empty()) {
				s.pop();
			}
			while(index <= n) {
				if(num == target[index]) {
					printf("1.");
					++index, ++num;
				}
				else if(!s.empty() && s.top() == target[index]) {
					printf("2.");
					s.pop();
					++index;
				}
				else if(num <= n) {
					printf("3.");
					s.push(num++);
				}
				else {
					printf("index %d, num %d", index, num);
					ok = false;
					break;
				}
			}
			printf("%s\n", ok == true ?  "Yes": "No");
		}
		if(!target[1]){
		 	printf("\n");
		}
		
	}
	return 0;	

}