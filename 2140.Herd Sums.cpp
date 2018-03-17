#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

/* （k+1）*（2*a+k）= 2*n */

int main () {
	int n, ans = 0;
	cin >> n;
	int m = 2*n;
	int upper = sqrt(double(m));
	for(int i = 1; i <= upper; i++) {  // 找出2n的所有因子
		if((m%i == 0) && (((m/i)-(i-1))%2 == 0))
			ans++;
	}
	cout << ans << endl;
}