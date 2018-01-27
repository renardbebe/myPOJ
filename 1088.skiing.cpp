#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define N 120
int matrix[N][N];
int dp[N][N];
int maxLen;
int r, c;

bool in(int i, int j) {
	return ((i >= 0) && (i < r) && (j >= 0) && (j < c));
}

int dfs(int i, int j) {
	if(dp[i][j])
		return dp[i][j];
	int cnt = 0;

	if(in(i-1, j) && (matrix[i][j] > matrix[i-1][j])) {
		cnt = max(cnt, dfs(i-1, j));
	}
	if(in(i+1, j) && (matrix[i][j] > matrix[i+1][j])) {
		cnt = max(cnt, dfs(i+1, j));
	}
	if(in(i, j-1) && (matrix[i][j] > matrix[i][j-1])) {
		cnt = max(cnt, dfs(i, j-1));
	}
	if(in(i, j+1) && (matrix[i][j] > matrix[i][j+1])) {
		cnt = max(cnt, dfs(i, j+1));
	}
	dp[i][j] = cnt + 1;  // dp[i][j] = max(dp[i-1][j],dp[i][j-1],dp[i+1][j],dp[i][j+1]) + 1
	return dp[i][j];
}

int main () {
	scanf("%d%d", &r, &c);
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			scanf("%d", &matrix[i][j]);
			dp[i][j] = 0;
		}
	}
	maxLen = 0;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			int path = dfs(i, j);
			maxLen = max(maxLen, path);
		}
	}
	printf("%d\n", maxLen);
	// system("pause");
}