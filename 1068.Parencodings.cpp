#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

#define N 55
int p[N], a[N], w[N];

int main () {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> p[i];
		a[0] = p[1];
		for(int i = 1; i < n; i++) {
			a[i] = p[i+1] - p[i];  // a[i]表示第i个右括号和第i+1个右括号间的左括号数
		}
		int j;
		for(int i = 1; i <= n; i++) {
			for(j = i-1; j >= 0; j--) {  // 匹配该右括号
				if(a[j]) {
					a[j]--;
					break;
				}
			}
			w[i] = i-j;
		}
		for(int i = 1; i <= n; i++) {
			if(i == 1) cout << w[i];
			else cout << " " << w[i];
		}
		cout << endl;
	}
}