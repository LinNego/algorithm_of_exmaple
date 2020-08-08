#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    string n;
    int m;
    while(cin >> n >> m) {
        long long ans = 0;
        for(int i = 0; i < n.size(); ++i) {
            ans = (ans * 10 + n[i] - '0') % m;
        }
        cout << ans << endl;
    }
    return 0;
}