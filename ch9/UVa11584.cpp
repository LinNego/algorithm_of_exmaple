//UVa11584.cpp
//IinNego

#include <iostream>
#include <utility>
#include <cstring>
using namespace std;

const int maxn = 1005;
int s[maxn][maxn], d[maxn], v[maxn][maxn];
char str[maxn];
bool is_palindromes(int i, int j) {
	if(i >= j) return 1;
	if(str[i] != str[j]) return 0;

	if(v[i][j]) return s[i][j];
	v[i][j] = 1;
	return s[i][j] = is_palindromes(i + 1, j - 1);
}
int main() {
	int n;
	cin >> n;
	while(n--) {
		scanf("%s", str + 1);
		memset(v, 0, sizeof(v));
		int len = strlen(str + 1);
		d[0] = 0;
		for(int i = 1; i <= len; ++i) {
			d[i] =  i;
			for(int j = 0; j < i; ++j) {
				if(is_palindromes(j + 1, i))
				d[i] = min(d[i], d[j] + 1);
			}
		}
		cout << d[len] << endl;
	}
}