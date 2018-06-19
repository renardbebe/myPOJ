#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

/* 最小邮票数 0-1背包 */

#define N 30
#define M 110
#define INF 999999
int value[N], dp[M];

int main () {
	int m, n;
	while(cin >> m) {  // 总价
		cin >> n;      // n张邮票
		for(int i = 0; i < n; i++) {
			cin >> value[i];
		}
		for(int i = 0; i < M; i++)
			dp[i] = (i == 0) ? 0 : INF;
		for(int i = 0; i < n; i++) {
			for(int j = m; j >= value[i]; j--) {
				dp[j] = min(dp[j], dp[j - value[i]] + 1);  // 凑成总价为j 所需要的最少邮票数
			}
		}
		if(dp[m] == INF) dp[m] = 0;
		cout << dp[m] << endl;
	}
}