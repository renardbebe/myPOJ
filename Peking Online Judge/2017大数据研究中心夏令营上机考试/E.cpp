#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

#define N 110
#define MAXN 1000005

int pos[N], value[N];
int near[N];  // 记录离i最近的可以开的餐馆
int dp[N];

/* dp */

int main () {
	int T;
	cin >> T;
	while(T--) {
		int n, k;
		cin >> n >> k;
		memset(near, 0, sizeof(near));
		for(int i = 1; i <= n; i++)
			cin >> pos[i];
		for(int i = 1; i <= n; i++)
			cin >> value[i];

		for(int i = 2; i <= n; i++) {
			for(int j = i-1; j >= 1; j--) {
				if(pos[i] - pos[j] > k) {
					near[i] = j;
					break;
				}
			}
		}
		memset(dp, 0, sizeof(dp));
		dp[1] = value[1];
		for(int i = 2; i <= n; i++) {
			dp[i] = max(dp[i-1], dp[near[i]] + value[i]);
		}
		cout << dp[n] << endl;
	}
}