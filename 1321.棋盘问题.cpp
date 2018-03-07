#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 10

int n, k, ans;
char table[N][N];
int col[N];

void dfs(int row, int step) {
	if(step == k) {
		ans++;
		return;
	}
	for(int i = row+1; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(table[i][j] == '#' && !col[j]) {
				col[j] = 1;
				dfs(i, step+1);
				col[j] = 0;
			}
		}
	}
}

int main () {
	while(~scanf("%d%d", &n, &k)) {
		if(n == -1 && k == -1) break;
		ans = 0;
		for(int i = 0; i < n; i++)
			cin >> table[i];
		memset(col, 0, sizeof(col));
		dfs(-1, 0);
		printf("%d\n", ans);
	}
}