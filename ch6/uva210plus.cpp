//uva210.cpp
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int maxn = 1000;
//vector<vector<string> > p;
char p[maxn][10];
int cur[maxn];
int var[26] = {0};
deque<int> ready, block;
int n, t1, t2, t3, t4, t5, q;
int cnt = 0;
void ini() {
	memset(p, 0, sizeof(p));
	memset(cur, 0, sizeof(cur));
	memset(var, 0 , sizeof(var));
	scanf("%d %d %d %d %d %d %d", &n, &t1, &t2, &t3, &t4, &t5, &q);
	getchar();
	int line = 0;
	cnt = 0;
	for(int i = 0; i < n; ++i) {
		fgets(p[line++], 10, stdin);
		int len = strlen(p[line - 1]);
		//cout << len - 1 << endl;
		p[line - 1][len - 1] = '\0';
		//cout << strlen(p[line - 1]);
		//printf("%s", p[line - 1]);
		++cnt;
		cur[i] = line - 1;
		//printf("%c\n", p[line - 1][2]);
		while(p[line - 1][2] != 'd') {
			fgets(p[line++], 10, stdin);
			//printf("%s\n", p[line - 1]);
			len = strlen(p[line - 1]);
			//cout << len << endl;
			p[line - 1][len - 1] = '\0';
			//printf("%s", p[line - 1]);
			++cnt;
		}
		ready.push_back(i);
	}	
}
void TestInput() {
	for(int i = 0; i < cnt; ++i) {
		printf("%s\n", p[i]);
	}
}
void Gvisit(int id) {
	for(deque<int>::iterator i = ready.begin(); i != ready.end(); ++i) {
		cout << *i << "G" << id << "id"  << endl;
	}
}
void run() {
	int sign_locked = 0;
	while(!ready.empty()) {
		int id = ready.front();
		//cout << "id:" <<  id << endl;
		ready.pop_front();
		//cout << c << endl;
		int r = q, sign_end = 0, sign_access = 0;
		while(r > 0) {
			int &sid = cur[id];
			//cout << "sid:" << sid << "p[id]" <<  p[sid] << endl;
			switch(p[sid][2]) {
				case '=':
					var[p[sid][0] - 'a'] = atoi(&p[sid][4]);
					//cout << var[p[sid][0] - 'a'] << "[]" << endl;	
					r -= t1;
					sid += 1;
					break;
				case 'i':
					cout << id + 1 << ": " << var[p[sid][6] - 'a'] << endl;
					r -= t2;
					sid += 1;
					break;
				case 'c':
					if(sign_locked) {
						sign_access = 1;
						block.push_back(id);
					//	cout << "why" << endl;
						//cout << "c id:" << id << endl;
						r -= t3;
					}
					else {
						sign_locked = 1;
						sid += 1;
						r -= t3;
					}
					break;
				case 'l': {
					sign_locked = 0;
					r -= t4;
					sid += 1;
					if(!block.empty()) {
						ready.push_front(block.front());
						block.pop_front();
					}
					
					break;
				}
				case 'd': {
					r -= t5;
					sign_end = 1;
					break;

				}
			}

			if(sign_end || sign_access) break;
		}
		//Gvisit(id);
		if(!sign_end && !sign_access) {
			//cout << id << "sign" << endl;
			ready.push_back(id);
		}
		
	}
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		ini();
		//TestInput();
		run();
		//Gvisit();
		if(T) printf("\n");
	}
	//cout << p[0][7] << endl;
	//TestInput();
	//cout << 324 << endl;
	return 0;
}