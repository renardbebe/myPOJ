#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/* 二维01背包 */

#define C 20+5
#define G 20+5
#define MAX_WEIGHT 25
#define ARM_LEN 15
#define MAXN 7500  // 将g个挂钩挂上的极限值：15*25*20 = 7500

int pos[C], weight[G];
int dp[G][MAXN*2];  // dp[i][j]: 表示使用i个砝码，使天平达到j位置（7500为平衡点）的方法数

int main () {
	int c, g;
	cin >> c >> g;  // C个挂钩位置 G个砝码
	for(int i = 1; i <= c; i++)
		cin >> pos[i];
	for(int i = 1; i <= g; i++)
		cin >> weight[i];

	dp[0][7500] = 1;  // 平衡点
	for(int i= 1; i <= g; i++) {  // 遍历砝码
		for(int j = 15000; j >= 1; j--) {
			for(int k = 1; k <= c; k++) {  // 遍历挂的位置
				dp[i][j] += dp[i-1][j+pos[k]*weight[i]];
			}
		}
	}
	cout << dp[g][7500] << endl;
	system("pause");
}