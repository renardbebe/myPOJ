#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 3407
#define MAXM 12885

/* 01背包问题 dp */

int weight[MAXN], value[MAXN], dp[MAXM];

int main () {
	int n, m;
	while(cin >> n >> m) {
		for(int i = 0; i < n; i++) {
			cin >> weight[i] >> value[i];
		}
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; i++) {
			for(int left = m; left >= weight[i]; left--) {
				dp[left] = max(dp[left - weight[i]] + value[i], dp[left]);
			}
		}
		cout << dp[m] << endl;
	}
}
