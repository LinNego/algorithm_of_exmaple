#include <iostream>
using namespace std;

/*  ax + by = gcd(a, b) */

int mgcd(int a, int b, int &x, int &y) {
    if(!b) {
        x = 1;
        y = 0;
        return a;
    }
    else {
        int ret = mgcd(b, a % b, y, x);
        /*证明过程 https://blog.csdn.net/destiny1507/article/details/81750874这个blog*/
        y -= x * (a / b);
        return ret;
    }
}

int main(int argc, char *argv[]) {
    int a, b;
    if(argc != 3) {
        printf("usage a <num1> <num2>\n");
        exit(0);
    }
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    int x, y;
    int ret = mgcd(a, b, x, y);
    cout << ret << " " << x << " " << y << endl;
    return 0;
}