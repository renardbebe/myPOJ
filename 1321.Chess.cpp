#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

#define N 10
int n, k, cnt;
char table[N][N];
int row[N], col[N], visit[N][N];

inline void dfs(int r, int c, int num) {
	if(num == k) {
		cnt++;
		return;
	}
	visit[r][c] = 1, row[r] = 1, col[c] = 1;

	for(int i = r+1; i <= n; i++) {  // 直接从下一行开始搜索
		if(!row[i]) {
			for(int j = 1; j <= n; j++) {
				if(!col[j] && table[i][j] == '#' && !visit[i][j]) {
					dfs(i, j, num+1);
				}
			}
		}
	}
	visit[r][c] = 0, row[r] = 0, col[c] = 0;
}

inline void init () {
	memset(visit, 0, sizeof(visit));
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	cnt = 0;
}

int main () {
	while(cin >> n >> k) {
		if(n == -1 && k == -1) break;

		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++)
				cin >> table[i][j];
		}

		init();
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(table[i][j] == '#') {
					dfs(i, j, 1);
				}
			}
		}
		cout << cnt << endl;
	}
}