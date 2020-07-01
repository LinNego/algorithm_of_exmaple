//test_prime_time.cpp
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>

const int maxn = 10000;
int isp[2 * maxn];

void get_primelist(int n) {
	for(int i = 2; i < maxn * 2; ++i) {
		if(!isp[i]) {
			for(int j = i * i; j < maxn * 2; j += i) {
				isp[j] = 1;
				printf("%d\n", j);
			}
		}
	}
}

void get_primelist_prime(int n) {
	for(int i = 2; i < maxn * 2; ++i) {
		for(int j = i * 2; j < maxn * 2; j += i) {
			isp[j] = 1;
			printf("%d\n", j);
		}
	}
}

void get_primelist_op1(int n) {
	int bound = ceil(sqrt(maxn * 2));
	for(int i = 2; i < maxn * 2; ++i) {
		for(int j = i * i; j < maxn * 2; j += i) {
			isp[j] = 1;
		}
	}
}

void get_primelist_op2(int n) {
	int bound = ceil(sqrt(maxn * 2));
	for(int i = 2; i < maxn * 2; ++i) {
		if(!isp[i])
		for(int j = i * i; j < maxn * 2; j += i) {
			isp[j] = 1;
		}
	}
}

void get_primelist_op3(int n) {
	int bound = ceil(sqrt(maxn * 2));
	for(int i = 2; i < bound; ++i) {
		if(!isp[i])
		for(int j = i * i; j < maxn * 2; j += i) {
			isp[j] = 1;
			printf("%d\n", j);
		}
	}
}


int main() {
	memset(isp, 0, sizeof(isp));
	get_primelist_prime(1);
	printf("%.2f\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}