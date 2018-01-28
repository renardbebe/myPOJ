#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define N 105

int n;
int tower[N][N];
long long dp[N][N];

int main () {
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			cin >> tower[i][j];
		}
	}
	memset(dp,0,sizeof(dp));
	for(int i = n-1; i >= 0; i--) {
		for(int j = 0; j <= i; j++) {
			if(i == n-1) dp[i][j] = tower[i][j];
			else {
				dp[i][j] = tower[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
			}
		}
	}
	cout << dp[0][0] << endl;
}