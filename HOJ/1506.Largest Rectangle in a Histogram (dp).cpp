#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 100010
#define INF 0x3f3f3f3f
int height[N], dp[N];  // dp[i]：以第 i 个矩形的高度为峰值的最大面积

int main () {
	int n;
	while(cin >> n && n) {
		memset(height, 0, sizeof(height));
		for(int i = 1; i <= n; i++)
			cin >> height[i];
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++) {
			dp[i] = height[i];
			int min_h = height[i];
			for(int j = i-1; j >= 1; j--) {
				min_h = min(min_h, height[j]);
				int area = min_h * (i-j+1);
				dp[i] = max(dp[i], area);
			}
		}
		int maxn = 0;
		for(int i = 1; i <= n; i++)
			maxn = max(maxn, dp[i]);
		cout << maxn << endl;
	}
}