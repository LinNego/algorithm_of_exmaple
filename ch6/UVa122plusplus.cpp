//UVa122plusplus.cpp
//Greatljc

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

struct Node {
	int value;
	bool h;
	Node *left, *right;
	Node(): h(0), left(nullptr), right(nullptr){}
};

Node *root;

const int maxn = 260;
Node nodes[maxn];
queue<Node*> freenodes;

void ini_freenodes() {
	for(int i = 0; i < maxn; ++i) {
		freenodes.push(&nodes[i]);
	}
}

Node* newnode() {
	Node *n = nullptr;
	if(!freenodes.empty()) {
		n = freenodes.front();
		freenodes.pop();	
		n->left = n->right = nullptr;
		n->h = false;
	}
	return n;
}

void deletenode(Node *n) {
	freenodes.push(n);
}

void get_str(string str, int &value, string &s) {
	int dot_pos = str.find(',');
	istringstream in(str.substr(1, dot_pos));
	in >> value;
	s = str.substr(dot_pos + 1, str.size() - dot_pos - 2);

}

bool insert_tree(int value, string s) {
	int len = s.size();
	//printf("len:%d ", len);
	Node *cur = root;
	for(int i = 0; i < len; ++i) {
		if(s[i] == 'L') {
			if(cur->left) {
				cur = cur->left;
			}
			else {
				cur->left = newnode();
				//printf("LL");
				cur = cur->left;
			}
		}
		else if(s[i] == 'R'){
			if(cur->right) {
				cur = cur->right;
			}
			else {
				cur->right = newnode();	
				//printf("RR");
				cur = cur->right;
			}
		}
	}
	if(cur->h) return false;
	cur->h = true;
	cur->value = value;
	return true;
}

bool level_travel(vector<int> &ans) {
	ans.clear();
	queue<Node*> q;
	q.push(root);
	Node *cur; 
	while(!q.empty()) {
		cur = q.front();
		q.pop();
		if(!cur->h) return false;
		ans.push_back(cur->value);
		//printf("%d ", cur->value);
		if(cur->left != nullptr) q.push(cur->left);
		if(cur->right != nullptr) q.push(cur->right);

	}	
	return true;
}

int main() {
	string n;
	ini_freenodes();
	while(cin >> n) {
		root = newnode();
		int value, ok = 1;
		string s;
		vector<int> v;
		get_str(n, value, s);
		
		if(!insert_tree(value, s)) 	{
			ok = 0;
		}
			
		//level_travel(v);
		while(cin >> n && n != string("()")) {
			get_str(n, value, s);
			if(!insert_tree(value, s)) {
				//printf("?????");
				ok = 0;
			}
			//level_travel(v);
			//printf("\n");
		}
		
		if(!ok || !level_travel(v)) {
			printf("not complete\n");
		}
		else {
			int len = v.size();
			for(int i = 0; i < len; ++i) {
				if(i != 0) printf(" ");
				printf("%d", v[i]);
			}
			printf("\n");
		}
		ini_freenodes();
	}
	return 0;
}
