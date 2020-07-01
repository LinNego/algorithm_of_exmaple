//对拍.cpp
//LinNego

#include <cstdio>

int main(int argc, char *argv[]) {
	FILE *f1 = fopen(argv[1], "r");
	FILE *f2 = fopen(argv[2], "r");
	while(1) {
		int n1, n2;
		int r1, r2;
		r1 = fscanf(f1, "%d", &n1);
		r2 = fscanf(f2, "%d", &n2);
		if(r1 == EOF && r2 == EOF) {
			printf("1\n");
			return 0;
		}
		if((r1 == EOF && r2 != EOF) || (r1 != EOF && r2 == EOF)) {
			printf("0\n");
			return 0;
		}
		if(n1 != n2) {
			printf("n1: %d n2: %d\n", n1, n2);
			printf("0\n");
			return 0;
		}

	}
}