#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

/* 求质因数个数 */

inline int cal(int n) {
	int cnt = 0;
	for(int i = 2; i <= sqrt(n); i++) {  // 每次缩小遍历范围
		while(n%i == 0) {
			n /= i;
			cnt++;
		}
	}
	if(n > 1) cnt++;  // 若是到方根N仍大于1，则必还有且只还有1个质因数
	return cnt;
}

int main () {
	int n;
	while(cin >> n) {
		cout << cal(n) << endl;
	}
}