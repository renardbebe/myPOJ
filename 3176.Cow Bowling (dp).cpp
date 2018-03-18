#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

#define N 355
int matrix[N][N], dp[N][N];

int main () {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++)
			cin >> matrix[i][j];
	}
	memset(dp, 0, sizeof(dp));
	for(int i = n-1; i >= 0; i--) {
		for(int j = n-1; j >= 0; j--) {
			dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + matrix[i][j];
		}
	}
	cout << dp[0][0] << endl;
	while(1);
}