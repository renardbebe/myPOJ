#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 1005
int a[N], dp[N];  // dp[k]: 表示以a[k]作为终点的最大上升子序列

int main () {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];

	dp[0] = 1;
	for(int i = 1; i < n; i++) {
		int maxn = 0;  // 不可以取-1，考虑 2 2 这样的情况
		for(int j = 0; j < i; j++) {
			if(a[i] > a[j] && maxn < dp[j])
				maxn = dp[j];
		}
		dp[i] = maxn + 1;
	}
	int maxLen = 0;
	for(int i = 0; i < n; i++) {
		maxLen = max(maxLen, dp[i]);
	}
	cout << maxLen << endl;
}