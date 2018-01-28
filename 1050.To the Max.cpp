#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define N 105

int n, matrix[N][N], sum[N][N];
int dp[N];  // 记录 j~i 列区域内的最大子矩阵和

int main () {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> matrix[i][j];
			sum[i][j] = sum[i][j-1] + matrix[i][j];  // 统计每一行的子段和
		}
	}
	int maxn = -1<<29;
	for(int i = 1; i <= n; i++) {  // 遍历列
		for(int j = 1; j < i; j++) {  // 遍历之前的列
			dp[1] = sum[1][i] - sum[1][j-1];
			for(int k = 2; k <= n; k++) {
				dp[k] = max(sum[k][i] - sum[k][j-1], sum[k][i] - sum[k][j-1] + dp[k-1]);
				maxn = max(maxn, dp[k]);
			}
		}
	}
	cout << maxn << endl;
	system("pause");
}