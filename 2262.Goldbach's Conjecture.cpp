#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 1000005
bool isprime[MAX];

void cal_prime() {
	for(int i = 2; i <= sqrt(MAX+0.5); i++) {
		if(isprime[i]) {
			for(int j = 2*i; j <= MAX; j += i) {
				isprime[j] = false;
			}
		}
	}
}

int main () {
	int n;
	memset(isprime, true, sizeof(isprime));
	cal_prime();
	while(cin >> n && n) {
		for(int i = 2; i <= (n/2); i++) {
			if(isprime[i] && isprime[n-i]) {
				printf("%d = %d + %d\n", n, i, n-i);
				break;
			}
		}
	}
}