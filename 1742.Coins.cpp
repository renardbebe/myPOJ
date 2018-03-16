#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXV 105
#define MAXM 100005

/* 多重背包 */

int a[MAXV], c[MAXV], dp[MAXM], num[MAXM];  // 记录当前总价格使用第i种硬币数量

int main () {
	int n, m;
	while(cin >> n >> m) {
		if(!n && !m) break;
		for(int i = 1; i <= n; i++) cin >> a[i];  // 每种硬币的价值
		for(int i = 1; i <= n; i++) cin >> c[i];  // 每种硬币的数量
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			memset(num, 0, sizeof(num));
			for(int j = a[i]; j <= m; j++) {  // 总价值
				if(!dp[j] && dp[j - a[i]] && num[j - a[i]] < c[i]) {
					dp[j] = 1;
					num[j] = num[j - a[i]] + 1;
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}