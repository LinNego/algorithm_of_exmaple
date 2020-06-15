/*
 *无平方因子plus
 *如果说一个数组来存储根号m前面的素数，开的数组量肯定不同超过int的最大值。
 *可是另外一个数组来存储平方，像筛素数那样，起码开10^12次方，开不了这么大。
 *所以在筛平方因子时，做了个映射。 m - n必然超不过10^7,所以这样i - n;具体代码32行。
 */
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 10000005;
long long value[maxn];
int visit[maxn];
void ini(long long n, long long m) {
	memset(value, 0, sizeof(value));
	memset(visit, 0, sizeof(visit));	
}
void Solve(long long n, long long m) {
	int ob1 = sqrt(m + 0.5), ob2 = sqrt(sqrt(m + 0.5) + 0.5);
	for(int i = 2; i <= ob2; ++i) {
		if(!visit[i]) {
			for(long long j = i * i; j <= ob1; j += i) {
				visit[j] = 1;
			}
		}
	}
	for(int i = 2; i <= ob1; ++i) {
		if(!visit[i]) {
			int index = i * i;
			for(int j = index; j <= m; j += index) {
				if(j >= n) {
					value[j - n] = 1;
				}
			}
		}
	}
}
int main() {
	long long n, m;
	cin >> n >> m;
	ini(n, m);
	Solve(n, m);
	int ob = m - n + 1, tol = 0;	
	for(int i = 0; i < ob; ++i) {
		if(!value[i]) tol++;
	}	
	cout << tol << endl;
	return 0;
}