#include <iostream>
using namespace std;

int main() {
	int a[5] = {1, 2, 3, 4, 5};
	int k = 4;
	printf("a[4]:%d\n", a[k--]);
	return 0;
}