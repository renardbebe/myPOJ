#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 105
int a[N];

int main () {
	int T;
	cin >> T;
	while(T--) {
		memset(a,0,sizeof(a));
		int n, ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(j%i == 0)
					a[j] = 1-a[j];  // 状态反转
			}
		}
		for(int i = 1; i <= n; i++) {
			if(a[i]) ans++;
		}
		cout << ans << endl;
	}
}