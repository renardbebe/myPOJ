#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define N 55
#define V 110
#define INF 0x3f3f3f3f

int R, C, num;
int road[V][V], dis[V], visit[V], vis[N][N], alien[N][N], step[N][N];
string *table;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct Point
{
	int x, y, id;
	Point() {}
	Point(int _x, int _y, int _i=0) {
		x = _x, y = _y, id = _i;
	}
};
Point point[V];

inline bool in (int row, int col) {
	return (row >= 0 && row < R && col >= 0 && col < C);
}

inline void bfs (Point p) {  // 求每个结点到其他结点的最短路
	queue<Point> q;
	memset(vis, 0, sizeof(vis));
	memset(step, 0, sizeof(step));
	q.push(p);
	vis[p.x][p.y] = 1;

	while(!q.empty()) {
		Point head = q.front();
		q.pop();
		if(alien[head.x][head.y]) {
			int id = alien[head.x][head.y];
			road[p.id][id] = road[id][p.id] = step[head.x][head.y];
		}

		for(int i = 0; i < 4; i++) {
			int next_x = head.x + dir[i][0];
			int next_y = head.y + dir[i][1];
			if(in(next_x, next_y) && !vis[next_x][next_y] && table[next_x][next_y] != '#') {
				Point tmp(next_x, next_y);
				q.push(tmp);
				vis[next_x][next_y] = 1;
				step[next_x][next_y] = step[head.x][head.y] + 1;
			}
		}
	}
}

inline int prim() {  // 求最小生成树
	int sum = 0;
	memset(visit, 0, sizeof(visit));
	for(int i = 1; i <= num; i++) {
		if(i == 1) dis[i] = 0;
		else dis[i] = road[1][i];
	}
	visit[1] = 1;

	for(int i = 1; i < num; i++) {
		int minn = INF, pos = 0;
		for(int j = 1; j <= num; j++) {
			if(!visit[j] && dis[j] < minn) {
				minn = dis[pos=j];
			}
		}
		visit[pos] = 1;
		sum += minn;
		// update
		for(int j = 1; j <= num; j++) {
			if(!visit[j] && road[pos][j] < dis[j]) {
				dis[j] = road[pos][j];
			}
		}
	}
	return sum;
}

int main () {
	int T;
	scanf("%d", &T);
	while(T--) {
		num = 0;
		memset(alien, 0, sizeof(alien));
		scanf("%d%d", &C, &R);
		// getchar();    WA !!
		string s;
		getline(cin, s);  // 读取 '\n'

		table = new string[N];
		for(int i = 0; i < R; i++) {
			getline(cin, table[i]);
			for(int j = 0; j < C; j++) {
				if(table[i][j] == 'S' || table[i][j] == 'A') {
					num++;
					point[num].x = i, point[num].y = j;
					alien[i][j] = num;
				}
			}
		}
		// init
		for(int i = 1; i <= num; i++) {
			for(int j = 1; j <= num; j++) {
				road[i][j] = (i == j) ? 0 : INF;
			}
		}
		for(int i = 1; i <= num; i++) {
			Point p(point[i].x, point[i].y, i);
			bfs(p);  // 对每个结点更新一次到其他点的最短路径
		}
		cout << prim() << endl;
	}
	system("pause");
}