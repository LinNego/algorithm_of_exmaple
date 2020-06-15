//UVa122plus.cpp
//Greatljc

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 256 + 5;
int Left[maxn], Right[maxn];
int values[maxn];
bool have_value[maxn];
int cnt, root;

void ini_tree() {
	cnt = root = 1;
	Left[root] = Right[root] = -1;
	memset(have_value, 0, sizeof(have_value));
}

char* get_str(char *str, int *value) {
	sscanf(&str[1], "%d", value);
	int len = strlen(str);
	str[len - 1] = 0;
	char *pos = strchr(str, ',') + 1;
	return pos;
}

int new_node() {
	int u = ++cnt;
	Left[u] = Right[u] = -1;
	have_value[u] = false;
	return u;


}

bool insert_node(char *pos, int value) {
	int len = strlen(pos);
	int t, cur = root;
	for(int i = 0; i < len; ++i) {
		if(pos[i] == 'L') {
			if(Left[cur] == -1) {
				 t = new_node();
				 Left[cur] = t;
				 cur = t;

			}
			else {
				cur = Left[cur];
			}
		}
		else if(pos[i] == 'R') {
			if(Right[cur] == -1) {
				t = new_node();	
				Right[cur] = t;
				cur = t;
			}
			else {
				cur = Right[cur];
			}
		}
	}
	if(have_value[cur]) return false;
	values[cur] = value;
	have_value[cur] = true;
	return true;
}

bool level_travel(vector<int> &v) {
	v.clear();
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int c = q.front();
		q.pop();
		if(Left[c] != -1) q.push(Left[c]);
		if(Right[c] != -1) q.push(Right[c]);
		if(!have_value[c]) return false;
		v.push_back(values[c]);
	}
	return true;
}

int main() {
	int value;
	char *pos, str[10];
	ini_tree();
	while(scanf("%s", str) != EOF) {
		int ok = 1;
		pos = get_str(str, &value);
	//	printf("%d ", value);
		if(!insert_node(pos, value)) {
			ok = 0;
		}
		while(scanf("%s", str) == 1 && strcmp(str, "()") != 0) {
			pos = get_str(str, &value);
			if(!insert_node(pos, value)) {
				//printf("no");
				ok = 0;
			}
		}
		vector<int> v;
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
		ini_tree();
	}
	/*
	scanf("%s", str);
	int value;
	//test_input(str, &value);
	char *pos = get_str(str, &value);
	*/
	return 0;
}
/*
void test_input(char *str, int *value) {
	char *pos = get_str(str, value);
	printf("%d\n", *value);
	printf("%s\n", pos);
}
*/