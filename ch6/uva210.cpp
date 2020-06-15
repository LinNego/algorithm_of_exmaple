//uva210.cpp
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int maxp = 1000;
vector<vector<string> > p;
vector<int> cur;
int var[26] = {0};
deque<int> ready, block;
int n, t1, t2, t3, t4, t5, q;
void ini() {
	memset(var, 0, sizeof(var));
	cur.clear();
	p.clear();
	cin >> n >> t1 >> t2 >> t3 >> t4 >> t5 >> q;
	getchar();
	for(int i = 0; i < n; ++i) {
		string str;
		p.push_back(vector<string>());
		cur.push_back(0);
		while(getline(cin, str) && str != string("end")) {
			//cout << str << endl;
			p[i].push_back(str);
		}
		p[i].push_back(string("end"));
	}
}
void TestInput() {
	for(int i = 0; i < n; ++i) {
		int size = p[i].size();
		for(int j = 0; j < size; ++j) {
			cout << p[i][j] << endl;
		}
	}
}
void run() {
	for(int i = 0; i < n; ++i) {
		ready.push_back(i);
	}
	int sign_locked = 0;
	while(!ready.empty()) {
		int id = ready.front();
		//cout << "id:" <<  id << endl;
		ready.pop_front();
		//cout << c << endl;
		int r = q, sign_end = 0, sign_access = 0;
		while(r > 0) {
			int &sid = cur[id];
			//cout << "sid:" << sid << "p[id]" <<  p[id][sid] << endl;
			switch(p[id][sid][2]) {
				case '=':
					var[p[id][sid][0] - 'a'] = atoi((p[id][sid].substr(4)).c_str());
					r -= t1;
					sid += 1;
					break;
				case 'i':
					cout << id + 1 << ": " << var[p[id][sid][6] - 'a'] << endl;
					r -= t2;
					sid += 1;
					break;
				case 'c':
					if(sign_locked) {
						sign_access = 1;
						block.push_back(id);
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
		if(!sign_end && !sign_access) {
			ready.push_back(id);
		}
		
	}
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		ini();
		run();
		if(T) printf("\n");
	}
	//ini();
	//run();
	//cout << p[0][7] << endl;
	//TestInput();
	//cout << 324 << endl;
	return 0;
}