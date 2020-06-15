/* BandWidth 带宽 */
// 最小化带宽
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int book[26]; // 记录26个英文字母出现哪些
int edge[26][26]; // 邻接矩阵
int minband; // 最小带宽
int vis[26]; // 表示每个字母在排列中所处的位置，1-结点个数
int path[10], tmp[10]; // 排列
int cnt; // 结点个数
void init() {
    memset(book, 0, sizeof(book));
    memset(edge, 0, sizeof(edge));
    minband = 999999;
    memset(vis, 0, sizeof(vis));
    memset(path, -1, sizeof(path));
    memset(tmp, -1, sizeof(tmp));
    cnt = 0;
}

void dfs(int index, int c,int band) {
    // index排列的位置，c表示当前字符,band表示当前带宽
    tmp[index] = c;
    vis[c] = index;
    // 更新带宽
    for (int i = 0; i < 26; i++) {
        if (edge[c][i] && vis[i]) {
            if (index - vis[i] > band) band = index - vis[i];
        }
    }
    // 注意这里剪枝的时候，一定要恢复原状 vis[] = 0;
    if (band > minband) {vis[c] = 0;  return; }
    // 寻找排列下一点
    for (int i = 0; i < 26; i++) {
        if (vis[i] == 0 && book[i]) dfs(index + 1, i, band);
    }
    vis[c] = 0; // 恢复原样
    if (index == cnt) {
        if (band < minband) {
            for (int i = 1; i <= index; i++) path[i] = tmp[i];
            minband = band;
        }
        return;
    }
}
int main() {
    string line;
    while (cin >> line && line[0] != '#') {
        init();
        for (int i = 0; i < line.length();) {
            char u = line[i]; // 起点
            for (i = i + 2; i < line.length() && line[i] != ';'; i++) {
                char v = line[i];
                edge[u - 'A'][v - 'A'] = 1;
                edge[v - 'A'][u - 'A'] = 1;
                book[u - 'A'] = book[v - 'A'] = 1;
            }
            i++;
        }// 建立完毕
        for (int i = 0; i < 26; i++) if (book[i]) cnt++;
        for (int i = 0; i < 26; i++) {
            if (book[i]) dfs(1, i, 0);
        }
        for (int i = 1; i < 10; i++) {
            if (path[i] != -1) printf("%c ", path[i] + 'A');
        }
        printf("-> %d\n", minband);
    }
    return 0;
}
/*
A:FB;B:GC;D:GC;F:AGH;E:HD
*/