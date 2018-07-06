#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define N 15
char table[N][N];
int visit[N][N];
int step[N][N];
int n, m, C;

bool in (int row, int col) {
	return (row >= 1 && row <= n && col >= 1 && col <= m);
}

void dfs (int row, int col, int depth) {
	if(!in(row, col)) {
		cout << depth << " step(s) to exit\n";
		return;
	}
	if(visit[row][col]) {
		cout << step[row][col] << " step(s) before a loop of " << depth-step[row][col] << " step(s)\n";
		return;
	}

	char ch = table[row][col];
	visit[row][col] = 1;
	step[row][col] = depth;
	switch(ch) {
		case 'N' : {
			int nextRow = row-1;
			int nextCol = col;
			dfs(nextRow, nextCol, depth+1);
			break;
		}
		case 'S' : {
			int nextRow = row+1;
			int nextCol = col;
			dfs(nextRow, nextCol, depth+1);
			break;
		}
		case 'W' : {
			int nextRow = row;
			int nextCol = col-1;
			dfs(nextRow, nextCol, depth+1);
			break;
		}
		case 'E' : {
			int nextRow = row;
			int nextCol = col+1;
			dfs(nextRow, nextCol, depth+1);
			break;
		}
	}
}

int main () {
	while(cin >> n >> m >> C) {
		if(!n && !m && !C) break;

		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cin >> table[i][j];
			}
		}

		// init
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				visit[i][j] = 0;
				step[i][j] = 0;
			}
		}

		dfs(1, C, 0);
	}
}