#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

#define N 110

int match[N][N], dp[N][N];

void init() {  // 匹配规则
	match['A']['A'] = match['C']['C'] = match['G']['G'] = match['T']['T'] = 5;
    match['A']['C'] = match['C']['A'] = match['A']['T'] = match['T']['A'] = -1;
    match[' ']['T'] = match['T'][' '] = -1;
    match['A']['G'] = match['G']['A'] = match['C']['T'] = match['T']['C'] = -2;
    match['G']['T'] = match['T']['G'] = match['G'][' '] = match[' ']['G'] = -2;
    match['A'][' '] = match[' ']['A'] = match['C']['G'] = match['G']['C'] = -3;
    match['C'][' '] = match[' ']['C'] = -4;
}

int main () {
	int T;
	init();
	cin >> T;
	while(T--) {
		int len1, len2;
		char s1[N], s2[N];
		scanf("%d%s", &len1, s1+1);  // 不从首地址开始写，从数组下标是1的位置开始写（首位空出来）
        scanf("%d%s", &len2, s2+1);

		dp[0][0] = 0;
		for(int i = 1; i <= len1; i++)
			dp[i][0] = dp[i-1][0] + match[s1[i]][' '];
		for(int i = 1; i <= len2; i++)
			dp[0][i] = dp[0][i-1] + match[' '][s2[i]];

		for(int i = 1; i <= len1; i++) {
			for(int j = 1; j <= len2; j++) {
				dp[i][j] = max( (dp[i][j-1] + match[' '][s2[j]]), (dp[i-1][j] + match[s1[i]][' ']) );
				dp[i][j] = max( dp[i][j], (dp[i-1][j-1] + match[s1[i]][s2[j]]) );
			}
		}
		cout << dp[len1][len2] << endl;
	}
}