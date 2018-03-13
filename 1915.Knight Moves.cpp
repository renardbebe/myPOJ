#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

#define N 305

int n, l;
int visit[N][N];

int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

struct Point
{
	int x;
	int y;
	int step;
	Point(){}
	Point(int _x, int _y, int _s) {
		x = _x;
		y = _y;
		step = _s;
	}
};

bool in(int x, int y) {
	return (x >= 0 && x < l && y >= 0 && y < l);
}

int bfs(Point a, Point b) {
	memset(visit, 0, sizeof(visit));
	queue<Point> q;
	q.push(a);
	visit[a.x][a.y] = 1;
	while(!q.empty()) {
		Point head = q.front();
		q.pop();
		if(head.x == b.x && head.y == b.y) {
			return head.step;
		}
		for(int i = 0; i < 8; i++) {
			int next_x = head.x + dx[i];
			int next_y = head.y + dy[i];
			if(!in(next_x, next_y) || visit[next_x][next_y]) continue;
			visit[next_x][next_y] = 1;
			Point tmp(next_x, next_y, head.step+1);
			q.push(tmp);
		}
	}
}

int main () {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> l;
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		Point a(x1, y1, 0);
		Point b(x2, y2, 0);
		cout << bfs(a, b) << endl;
	}
}