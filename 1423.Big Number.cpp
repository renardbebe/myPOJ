#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main () {
	int T, n;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		double ans = 0.0;
		for(int i = 1; i <= n; i++) {
			ans += log10(double(i));
		}
		printf("%d\n", int(ans)+1);
	}
}