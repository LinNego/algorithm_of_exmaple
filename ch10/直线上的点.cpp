//直线上的点
#include <iostream>
using namespace std;

int gcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int ret = gcd(b, a % b, y, x);
    y -= x * (a / b);
    return ret;
}


int main(int argc, char *argv[]) {
    if(argc != 4) {
        printf("usage a <num1> <num2> <num3>\n");
        exit(0);
    }
    int a = atoi(argv[1]), b = atoi(argv[2]), c = atoi(argv[3]);
    int x, y, ret;
    ret = gcd(a, b, x, y);
    a = a / ret;
    b = b / ret;
    for(int k = 0; ; ++k) {
        x1 = x - k * b;
        y1 = y + k * a;
        if(x1 >= 0 && x1 <= 100 && y1 >= 0 && y2 <= 100) {
            printf("%d %d\n", x1, y1);
        }
        
    }
}