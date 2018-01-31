#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

#define N 1005
int dp[N][N];  // dp[i][j]: A串的前i个字符和B串的前j个字符的最长公共子序列长度
char s1[N], s2[N];

int main () {
	while(~scanf("%s%s", &s1, &s2)) {
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		memset(dp, 0, sizeof(dp));

		for(int i = 1; i <= len1; i++) {
			for(int j = 1; j <= len2; j++) {
				if(s1[i-1] == s2[j-1])
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
		printf("%d\n", dp[len1][len2]);
	}
}