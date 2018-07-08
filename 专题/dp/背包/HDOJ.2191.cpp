#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/* 多重背包 */

#define N 110

int dp[N], weight[N], cost[N], num[N];  // dp[i]: 用i元可以买到的最多大米重量

int main () {
	int T, n, m;  // n: 经费 m：大米种类
	cin >> T;
	while(T--) {
		cin >> n >> m;
		for(int i = 0; i < m; i++) {
			cin >> cost[i] >> weight[i] >> num[i];
		}
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < m; i++) {
			for(int k = 1; k <= num[i]; k++) {
				for(int j = n; j >= cost[i]; j--) {
					dp[j] = max(dp[j], dp[j - cost[i]] + weight[i]);
				}
			}
		}
		cout << dp[n] << endl;
	}
}