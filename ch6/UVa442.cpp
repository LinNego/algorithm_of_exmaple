//UVa442.cpp
//Greatljc


#include <cstdio>
#include <stack>
#include <iostream>
#include <cctype>
using namespace std;
struct Matrix {
	int row, col;
	Matrix(int row = 0, int col = 0): row(row), col(col) {}
};

Matrix m[26];

int solve(string &exp, stack<Matrix> &sta) {
	int ans = 0;
	int len = exp.size();
	for(int i = 0;  i < len; ++i) {
		if(isupper(exp[i])) {
			sta.push(m[exp[i] - 'A']);
		}
		if(exp[i] == ')') {
			if(!sta.empty()) {
				Matrix m1 = sta.top();
				//cout << m1.row << endl;
				sta.pop();
				if(!sta.empty()) {
					Matrix m2 = sta.top();
					//cout << m2.col << endl;
					sta.pop();
					if(m1.row == m2.col) {
						ans += m1.col * m1.row * m2.row;
						sta.push(Matrix(m2.row, m1.col));
					}
					else {
						return -1;
					}
				}
			}
		}
	}
	return ans;
}
int main() {
	int n;
	scanf("%d", &n);
	getchar();
	for(int i = 0; i < n; ++i) {
		char ch;
		int row, col;
		scanf("%c %d %d", &ch, &row, &col);
		getchar();
		m[ch - 'A'].row = row;
		m[ch - 'A'].col = col;
	}
	string exp;
	while(cin >> exp) {
		stack<Matrix> sta;
		int ans = 0;
		if((ans = solve(exp, sta)) != -1) {
			printf("%d\n", ans);
		}
		else {
			printf("error\n");
		}
	}
	return 0;
}