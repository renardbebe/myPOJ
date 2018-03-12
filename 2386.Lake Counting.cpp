#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

#define N 105

int n, m, cnt;
int visit[N][N];
char field[N][N];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool in(int row, int col) {
	return (row >= 1 && row <= n && col >= 1 && col <= m);
}

bool tillEnd(int row, int col) {
	for(int i = 0; i < 8; i++) {
		int next_row = row + dx[i];
		int next_col = col + dy[i];
		if(!(in(next_row, next_col) && !visit[next_row][next_col] && field[next_row][next_col] == 'W')) return false;
	}
	return true;
}

void dfs(int row, int col, int area) {
	for(int i = 0; i < 8; i++) {
		int next_row = row + dx[i];
		int next_col = col + dy[i];
		if(in(next_row, next_col) && !visit[next_row][next_col] && field[next_row][next_col] == 'W') {
			visit[next_row][next_col] = 1;
			dfs(next_row, next_col, area+1);
		}
	}
}

int main () {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++)
			cin >> field[i][j];
	}
	memset(visit, 0, sizeof(visit));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(!visit[i][j] && field[i][j] == 'W') {
				visit[i][j] = 1;
				dfs(i, j, 1);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}