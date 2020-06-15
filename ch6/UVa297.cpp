//UVa297.cpp
//Greatljc

#include <cstdio>
#include <cstring>

const int len = 32;
const int maxn = 1024 + 60;
char s[maxn];
char buf[len][len];
int cnt;
void draw(char *s, int &p, int r, int c, int w) {
	char ch = s[p++];
	if(ch == 'p') {
		draw(s, p, r, c + w / 2, w / 2);
		draw(s, p, r, c, w / 2);
		draw(s, p, r + w / 2, c, w / 2);
		draw(s, p, r + w / 2, c + w / 2, w / 2);
	}
	else if(ch == 'f') {
		for(int i = r; i < r + w; ++i) {
			for(int j = c; j < c + w; ++j) {
				if(!buf[i][j]) {
					buf[i][j] = 1;
					++cnt;
				}
			}
		}
	}
}

void ini() {
	memset(s, 0, sizeof(s));
	memset(buf, 0, sizeof(buf));
	cnt = 0;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		ini();
		for(int j = 0; j < 2; ++j) {
			scanf("%s", s);
			int p = 0;
			draw(s, p, 0, 0, 32);
		}
		printf("There are %d black pixels.\n", cnt);
	}	
	return 0;
}