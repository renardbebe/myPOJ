#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

#define N 10010
int num[N], sum[N], mod[N];

/* 组合数学 鸽巢原理
   从 n个数中选出 m个数，使其和为 n的倍数
   https://blog.csdn.net/qq_32426313/article/details/53046815
 */

int main() {
	int n;
	cin >> n;
	memset(mod, -1, sizeof(mod));
	memset(sum, 0, sizeof(sum));
	for(int i = 0; i < n; i++) {
		cin >> num[i];
		if(i > 0)
			sum[i] = sum[i-1] + num[i];
		else
			sum[i] = num[i];
	}
	for(int i = 0; i < n; i++) {
		if(sum[i] % n == 0) {
			cout << i+1 << endl;
			for(int j = 0; j <= i; j++)
				cout << num[j] << endl;
			break;
		}
		else {
			int m = sum[i] % n;
			if(mod[m] != -1) {  // 存在余数相同的情况
				int t = i - mod[m];
				cout << t << endl;
				for(int j = mod[m]+1; j <= i; j++)
					cout << num[j] << endl;
				break;
			}
			mod[m] = i;
		}
 	}
}