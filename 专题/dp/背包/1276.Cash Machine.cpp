#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

/* 多重背包 */

struct Thing
{
	int number;
	int value;
} a[20];

int dp[100010];  // 记录最大价值

int main () {
	int n, sum;
	while(cin >> sum >> n) {
		for(int i = 1; i <= n; i++)
			cin >> a[i].number >> a[i].value;
		if(!sum || !n) {
			cout << 0 << endl;
			continue;
		}
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		int maxValue = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = maxValue; j >= 0; j--) {
				if(dp[j]) {
					for(int k = 1; k <= a[i].number; k++) {
						int tmp = j + k * a[i].value;
						if(tmp > sum) continue;
						dp[tmp] = 1;
						maxValue = max(maxValue, tmp);
					}
				}
			}
		}
		cout << maxValue << endl;
	}
}