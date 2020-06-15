//UVa11988.cpp
//Greatljc

#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 100005;
int ne[maxn];
char s[maxn];
int main() {	

	while(scanf("%s", s + 1) != EOF) {
	//	memset(next, 0, sizeof(next));
		int len = strlen(s + 1), cur = 0, begin = 0, last = 0;
		ne[0] = 0;
		for(int i = 1; i < len + 1; ++i) {
			if(s[i] == '[') {
				cur = 0;

			}
			else if(s[i] == ']') {
				cur = last;
			}
			else {
				ne[i] = ne[cur];
				ne[cur] = i;
				if(cur == last) last = i;
				cur = i;

			}
		}
		int i = ne[0];
		while(s[i] != '\0') {
			putchar(s[i]);
			i = ne[i];
		}
		putchar(10);

	}
	return 0;
}