//HDOJ1004
//LinNego
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n;
    while(cin >> n && n) {
        map<string, int> ball;
        string s;
        for(int i = 0; i < n; ++i) {
           cin >> s; 
           ++ball[s];
        }
        string cnt;
        int num = -1;
        for(auto p: ball) {
            if(p.second > num) {
                num = p.second;
                cnt = p.first;
            }
        }
        cout << cnt << endl; 
    }
}