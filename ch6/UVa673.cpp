//UVa673.cpp
//Greatljc

#include <string>
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

char par[2] = {')', ']'}; //1.(    2. [
map<char, int> left_num;

bool solve(int &i, string &str, char num) {
	int len = str.size();
	bool sign = 1, temp = 0;
	i = i + 1;
	for(; i < len; ++i) {
		if(left_num.find(str[i]) != left_num.end()) {
			if(!solve(i, str, str[i])) {
				sign = 0;
				break;
			}
		}
		else {
			if(par[left_num[num]] == str[i]) {
				temp = 1;
				break;
			}
		}
	}
	return sign && temp;
}

int main() {
	int n;
	cin >> n;
	left_num['('] = 0;
	left_num['['] = 1;
	getchar();
	while(n--) {
		string str;
		getline(cin, str);
		int len = str.size(), pre;
		bool sign = 1;
		for(int i = 0; i < len; ++i) {
			if(left_num.find(str[i]) != left_num.end()) {
				if(!solve(i, str, str[i])) {
					sign = 0;
					break;
				}
			}
			else {
				sign = 0;
				break;	
			}
		}
		printf("%s\n", sign ? "Yes": "No");
	}
	return 0;
}