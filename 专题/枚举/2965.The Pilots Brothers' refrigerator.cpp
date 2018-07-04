#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

int matrix[5][5];
int step;
bool flag;

vector<int> Row;
vector<int> Col;

bool check() {
	for(int i = 1; i <= 4; i++) {
		for(int j = 1; j <= 4; j++) {
			if(matrix[i][j] == 0) return false;
		}
	}
	return true;
}

void flip(int row, int col) {
	for(int j = 1; j <= 4; j++)
		matrix[row][j] = 1 - matrix[row][j];
	for(int i = 1; i <= 4; i++)
		matrix[i][col] = 1 - matrix[i][col];
	matrix[row][col] = 1 - matrix[row][col];
}

void dfs(int row, int col, int depth) {
	if(depth == step) {
		flag = check();
		if(flag) {
			cout << step << endl;
			for(int i = 0; i < Row.size(); i++) {
				cout << Row[i] << " " << Col[i] << endl;
			}
		}
		return;
	}
	if(row == 5 || flag) return;

	flip(row, col);
	Row.push_back(row);
	Col.push_back(col);
	if(col == 4) dfs(row+1, 1, depth+1);
	else dfs(row, col+1, depth+1);

	// 还原
	flip(row, col);
	Row.pop_back();
	Col.pop_back();
	if(col == 4) dfs(row+1, 1, depth);
	else dfs(row, col+1, depth);
}

int main () {
	char ch;
	for(int i = 1; i <= 4; i++) {
		for(int j = 1; j <= 4; j++) {
			cin >> ch;
			if(ch == '-') matrix[i][j] = 1;  // open
			else matrix[i][j] = 0;
		}
	}
	flag = false;
	for(step = 0; step <= 32; step++) {
		Row.clear();
		Col.clear();
		dfs(1, 1, 0);
		if(flag) break;
	}
	system("pause");
}