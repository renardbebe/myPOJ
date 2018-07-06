#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

// 三维bfs

#define N 35
char table[N][N][N];
int visit[N][N][N];
int l, r, c;

int direct[6][3] = {{1, 0, 0}, {-1, 0, 0},
                    {0, 1, 0}, {0, -1, 0},
                    {0, 0, 1}, {0, 0, -1}};

struct Point
{
	int x;
	int y;
	int z; // level
	int step;
	Point() {}
	Point(int _x, int _y, int _z, int s) {
		x = _x; y = _y; z = _z; step = s;
	}
};

bool in (int row, int col, int level) {
	return (row >= 1 && row <= l && col >= 1 && col <= r && level >= 1 && level <= c);
}

int bfs(Point s) {
	queue<Point> q;
	q.push(s);
	visit[s.x][s.y][s.z] = 1;
	while(!q.empty()) {
		Point head = q.front();
		q.pop();

		for(int d = 0; d < 6; d++) {
			int next_x = head.x + direct[d][0];
			int next_y = head.y + direct[d][1];
			int next_z = head.z + direct[d][2];
			if(in(next_x, next_y, next_z) && !visit[next_x][next_y][next_z] && table[next_x][next_y][next_z] != '#') {
				if(table[next_x][next_y][next_z] == 'E') {
					return head.step+1;
				}
				Point node(next_x, next_y, next_z, head.step+1);
                q.push(node);
                visit[next_x][next_y][next_z] = 1;
			}
		}
	}
	return -1;
}

int main () {
	while(cin >> l >> r >> c) {
		if(!l && !r && !c) break;

		Point start;
		for(int k = 1; k <= l; k++) {  // x
			for(int i = 1; i <= r; i++) {  // y
				for(int j = 1; j <= c; j++) {  // z
					cin >> table[k][i][j];
					if(table[k][i][j] == 'S') {
						start.x = k; start.y = i; start.z = j; start.step = 0;
					}
				}
			}
		}
		memset(visit, 0, sizeof(visit));
		int ret = bfs(start);
		if(ret != -1) cout << "Escaped in " << ret << " minute(s).\n";
		else cout << "Trapped!\n";
	}
}