#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

#define N 25
char matrix[N][N];
bool visit[N][N];
int w, h, step;

const int direc[4][2] = {
    {0, -1},
    {1, 0},
    {0, 1},
    {-1 ,0},
};

bool in(int x, int y) {
	return (x >= 0 && x < h && y >= 0 && y < w);
}

int dfs(int x, int y) {
	visit[x][y] = true;
	for(int i = 0; i < 4; i++) {
		int curx = x + direc[i][0];
		int cury = y + direc[i][1];
		if(in(curx, cury) && !visit[curx][cury] && matrix[curx][cury] == '.') {
			dfs(curx, cury);
			step++;
		}
	}
	return step;
}

int main () {
	while(cin >> w >> h && w && h) {
		step = 1;
		memset(visit,false,sizeof(visit));
		int posx = 0, posy = 0;
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < w; j++) {
				cin >> matrix[i][j];
				if(matrix[i][j] == '@') {
					posx = i;
					posy = j;
				}
			}
		}
		cout << dfs(posx, posy) << endl;
	}
}