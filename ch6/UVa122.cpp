//UVa122.cpp
//Greatljc

#include <cstdio>
#include <string>
#include <queue>
#include <sstream>
#include <iostream>
using namespace std;

struct Node {
	bool h;
	Node *left, *right;
	int value;
	Node(): h(0), left(nullptr), right(nullptr), \
		value(value) {}
};
Node *root;

void test_input(int v, string s) {
	cout << v << " " << s << endl;
}

void get_str(string str, int &value, string &s) {
	int dot_pos = str.find(',');
	istringstream in(str.substr(1, dot_pos));
	in >> value;
	s = str.substr(dot_pos + 1, str.size() - dot_pos - 2);
	//test_input(value, s);

}

void remove_tree(Node *root) {
	if(root->left)  remove_tree(root->left);  //这个做法可能有点冒险，万一root的一开始就是NULL的，那么可能会出问题。
	if(root->right) remove_tree(root->right);
	delete root;
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
				cur->left = new Node();
				//printf("LL");
				cur = cur->left;
			}
		}
		else if(s[i] == 'R'){
			if(cur->right) {
				cur = cur->right;
			}
			else {
				cur->right = new Node();	
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

void clear(queue<Node*> &q) {
	queue<Node*> e;
	swap(q, e);
}

bool level_travel(vector<int> &ans) {
	ans.clear();
	queue<Node*> q;
	clear(q);
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
	while(cin >> n) {
		root = new Node();
		int value, ok = 1;
		string s;
		vector<int> v;
		get_str(n, value, s);
		if(!insert_tree(value, s)) 	{
			//printf("????");
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

		remove_tree(root); //我也刚刚好，确保了root不会为NULL
		，，
	}
	return 0;
}