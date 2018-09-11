#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

#define N 15
char table[N][N];
int R, C, S, visit[N][N], step[N][N];

inline bool in (int row, int col) {
	return (row >= 1 && row <= R && col >= 1 && col <= C);
}

inline int dfs (int row, int col, int move) {
	if(!in(row, col)) {
		cout << move << " step(s) to exit" << endl;
		return 0;
	}
	if(visit[row][col]) {
		cout << step[row][col] << " step(s) before a loop of " << move - step[row][col] << " step(s)" << endl;
		return 0;
	}

	visit[row][col] = 1;
	step[row][col] = move;
	switch(table[row][col]) {
		case 'N' : {
			dfs(row-1, col, move+1);
			break;
		}
		case 'S' : {
			dfs(row+1, col, move+1);
			break;
		}
		case 'E' : {
			dfs(row, col+1, move+1);
			break;
		}
		case 'W' : {
			dfs(row, col-1, move+1);
			break;
		}
	}
}

int main () {
	while(cin >> R >> C >> S && R && C && S) {
		for(int i = 1; i <= R; i++) {
			for(int j = 1; j <= C; j++)
				cin >> table[i][j];
		}
		memset(visit, 0, sizeof(visit));
		memset(step, 0, sizeof(step));
		dfs(1, S, 0);
	}
}