#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

/* 整数拆分方法数
   f(2m + 1) = f(2m)，
   f(2m) = f(2m - 1) + f(m)
*/

#define N 1000010
#define M 1000000000
int f[N];

void init() {
	f[1] = 1;
	for(int i = 2; i <= N; i++) {
		if(i % 2 == 0) {
			f[i] = (f[i-1] + f[i/2]) % M;
		}
		else f[i] = f[i-1];
	}
}

int main () {
	int n;
	init();
	while(cin >> n) {
		cout << f[n] % M << endl;
	}
}