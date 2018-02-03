#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int matrix[6][6];
int step;
bool flag;

const int dirc[5][2] = {
	{0, 0},
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1},
};

bool check() {
	int c = matrix[1][1];
	for(int i = 1; i <= 4; i++) {
		for(int j = 1; j <= 4; j++) {
			if(matrix[i][j] != c) return false;
		}
	}
	return true;
}

bool in(int row, int col) {
	return (row >= 1 && row <= 4 && col >= 1 && col <= 4);
}

void flip(int row, int col) {
	for(int i = 0; i < 5; i++) {
		int next_row = row + dirc[i][0];
		int next_col = col + dirc[i][1];
		if(in(next_row, next_col))
			matrix[next_row][next_col] = 1 - matrix[next_row][next_col];
	}
}

void dfs(int row, int col, int depth) {
	if(depth == step) {
		flag = check();
		return;
	}
	if(flag || row == 5) return;

	flip(row, col);
	if(col == 4) dfs(row+1, 1, depth+1);
	else dfs(row, col+1, depth+1);

	// 还原
	flip(row, col);
	if(col == 4) dfs(row+1, 1, depth);
	else dfs(row, col+1, depth);
}

int main () {
	for(int i = 1; i <= 4; i++) {
		for(int j = 1; j <= 4; j++) {
			char ch;
			cin >> ch;
			if(ch == 'w') matrix[i][j] = 0;
			else matrix[i][j] = 1;
		}
	}
	for(step = 0; step <= 16; step++) {  // 枚举所需步数
		dfs(1,1,0);
		if(flag) break;
	}
	if(flag) cout << step << endl;
	else cout << "Impossible" << endl;
}