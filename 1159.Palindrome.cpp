#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

short dp[5005][5005];
char a[5010];

int main () {
	int n;
	cin >> n;
	getchar();
	gets(a);
	for(int i = 0; i < n; i++) {
		dp[i][i] = 0;
		if(a[i] == a[i+1]) dp[i][i+1] = dp[i][i];
		else dp[i][i+1] = dp[i][i] + 1;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < n-i; j++) {
			if(a[j] == a[i+j])
				dp[j][i+j] = dp[j+1][i+j-1];
			else
				dp[j][i+j] = min(dp[j+1][i+j], dp[j][i+j-1]) + 1;
		}
	}
	cout << dp[0][n-1] << endl;
	system("pause");
}