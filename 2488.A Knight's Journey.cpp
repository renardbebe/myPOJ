#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

#define N 30
int T, p, q;
bool flag;
int visit[N][N];

// 字典序最小的行走方向 !!
int dir[8][2] = {{-1, -2}, {1, -2},
                 {-2, -1}, {2, -1},
                 {-2, 1}, {2, 1},
                 {-1, 2}, {1, 2}};

struct Point
{
	int x, y;
	Point() {}
	Point(int _x, int _y) {
		x = _x, y = _y;
	}
};
Point path[N*N];

inline bool in (int row, int col) {
	return (row >= 1 && row <= p && col >= 1 && col <= q);
}

inline void dfs (int row, int col, int depth) {
	path[depth].x = row, path[depth].y = col;  // 记录路径

	if(depth == p*q) {
		flag = true;
		return;
	}

	for(int i = 0; i < 8; i++) {
		int next_x = row + dir[i][0];
		int next_y = col + dir[i][1];
		if(in(next_x, next_y) && !visit[next_x][next_y] && !flag) {
			visit[next_x][next_y] = 1;
			dfs(next_x, next_y, depth+1);
			visit[next_x][next_y] = 0;  // 回溯
		}
	}
}

int main () {
	cin >> T;
	for(int kase = 1; kase <= T; kase++) {
		cout << "Scenario #" << kase << ":\n";
		cin >> p >> q;
		for(int i = 1; i <= p; i++) {
			for(int j = 1; j <= q; j++) {
				flag = false;
				memset(visit, 0, sizeof(visit));

				visit[i][j] = 1;
				dfs(i, j, 1);
				if(flag) break;
			}
			if(flag) break;
		}

		if(flag) {
			for(int i = 1; i <= p*q; i++) {
				cout << char(path[i].y - 1 + 'A') << path[i].x;
			}
			cout << endl;
		}
		else {
			cout << "impossible\n";
		}
		if(kase != T)
			cout << endl;
	}
	system("pause");
}