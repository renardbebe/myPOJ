#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

/* 阶乘后面的0都是由2和5相乘得到的
   而2每两个就有一个，所以个数足够，不考虑
   只需要考虑因数5的个数即可
 */

int main () {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		int cnt = 0;
		while(n) {
			cnt += n/5;
			n /= 5;
		}
		cout << cnt << endl;
	}
}