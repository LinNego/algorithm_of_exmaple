//Greatljc 
//UVa1572.cpp

/*
 *关键是有向图是怎么建立的。思维转变
 */

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxn = 52;
int graph[maxn][maxn];
int c[maxn];

int getU(char a1, char a2) {
    int ret = (a1 - 'A') + (a2 == '+' ? 0: 26);
    //printf("retu:%d ", ret);
    return ret;
}
int getV(char b1, char b2) {
    int ret = (b1 - 'A') + (b2 == '+'? 26: 0);
    //printf("retv:%d ", ret);
    return ret;
}

void connect(char a1, char a2, char b1, char b2) {
  //  printf("%c %c %c %c\n", a1, a2, b1, b2);
    if(a1 == '0' || b1 == '0') return ;
    int u = getU(a1, a2);
    //printf("u: %d ", u);
    int v = getV(b1, b2);
    //printf("v: %d \n", v);
    graph[u][v] = 1;
}

bool dfs(int u) {
    c[u] = -1; 
    for(int v = 0; v < 52; ++v) {
        if(graph[u][v]) {
            if(c[v] < 0) return true;
            if(!c[v] && dfs(v)) return true;
        }
    }
    c[u] = 1;
    return false;
}

bool topsort() {
    memset(c, 0, sizeof(c));
    for(int u = 0; u < 52; ++u) {
        if(!c[u]) {
            if(dfs(u)) return true;
        }
    }
    return false;
}


int main() {
    int n;
    while(cin >> n) {
        memset(graph, 0, sizeof(graph));
        while(n--) {
            char chs[10];
            scanf("%s", chs);
            for(int i = 0; i < 4; ++i) {
                for(int j = 0; j < 4; ++j) {
                    if(i != j) {
                        //printf("%c %c %c %c\n", chs[i * 2], chs[i * 2 + 1], chs[j * 2], chs[j * 2 + 1]);
                        connect(chs[i * 2], chs[i * 2 + 1], chs[j * 2], chs[j * 2 + 1]);
                    }
                }
            }
        }
        if(topsort()) printf("unbounded\n");
        else printf("bounded\n");
    }
    return 0;
}