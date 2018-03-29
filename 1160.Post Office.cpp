#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

#define N 500
#define INF 0x3f3f3f3f
int n, p;
int pos[N];
int w[N][N], dp[N][35];

/* 区间 dp

   dp[i][j]: 表示在前i个村庄建立j个邮局的最小距离

   w[i][j]:  表示两个村庄之间建立一个邮局的最小距离（中点）

   转移方程: dp[i][j] = min(dp[i][j], dp[k][j-1] + w[k+1][i]) （j-1<=K<=i-1） */

int main () {
	cin >> n >> p;
	for(int i = 1; i <= n; i++)
		cin >> pos[i];
	memset(w, 0, sizeof(w));
	// 初始化w
	for(int i = 1; i <= n; i++) {
		for(int j = i+1; j <= n; j++) {
			w[i][j] = w[i][j-1] + pos[j] - pos[(i+j)/2];
		}
	}
	// 边界条件
	memset(dp, INF, sizeof(dp));
	for(int i = 1; i <= n; i++) {
		dp[i][1] = w[1][i];
		dp[i][i] = 0;
	}
	for(int j = 2; j <= p; j++) {
		for(int i = j+1; i <= n; i++) {
			dp[i][j] = INF;
			for(int k = j-1; k <= i-1; k++) {  // 枚举分点
				dp[i][j] = min(dp[i][j], (dp[k][j-1] + w[k+1][i]));
			}
		}
	}
	cout << dp[n][p] << endl;
}