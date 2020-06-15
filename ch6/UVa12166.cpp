//UVa12166.cpp
//Greatljc

#include <cstdio>
#include <map>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <sstream>
using namespace std;

map<long long, long long> m;

string tree;
long long sum;

void solve(int depth, int &b) {
	char ch;
	while((ch = tree[++b]) != ']') {
		if(ch == '[') {
			solve(depth + 1, b);
		}
		else if(isdigit(ch)) {
			string str;
			while(isdigit(tree[b])) {
				str += tree[b];
				++b;
			}
			--b;
			istringstream in(str);
			long long tol;
			in >> tol; 
			tol = tol * (1 << depth);
			//cout << "tol" << tol << endl;
			m[tol]++;
			++sum;
		}
	}
}

int main() {
	//ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		cin >> tree;
		sum = 0;
		m.clear();
		if(tree[0] != '[') {
			cout << sum << endl;
			continue;
		}
		int b = 0;
		solve(1, b);
		long long maxi = -1;
		for(auto i = m.begin(); i != m.end(); ++i) {
			maxi = max(maxi, i->second);
		}
		cout << sum - maxi << endl;
	}
	return 0;
}