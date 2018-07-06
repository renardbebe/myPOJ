#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define N 110
int K, A, B, n, m;
int exist[N][N];

char ori_L[30][5], ori_R[30][5];

struct Robot
{
	int id;
	int x;
	int y;
	char orientation;
	Robot() {}
	Robot(int i, int _x, int _y, char ch) {
		id = i;
		x = _x;
		y = _y;
		orientation = ch;
	}
}robot[N];

inline bool in(int row, int col) {
	return (row >= 1 && row <= A && col >= 1 && col <= B);
}

inline bool over(int curId) {
	for(int i = 1; i <= A; i++) {
		for(int j = 1; j <= B; j++) {
			exist[i][j] = 0;
		}
	}

	if(!in(robot[curId].x, robot[curId].y)) {
		cout << "Robot " << curId<< " crashes into the wall\n";
		return true;
	}

	for(int i = 1; i <= n; i++) {
		if(robot[i].id != curId) {
			exist[robot[i].x][robot[i].y] = robot[i].id;
		}
	}
	int id = exist[robot[curId].x][robot[curId].y];
	if(id) {
		cout << "Robot " << curId << " crashes into robot " << id << "\n";
		return true;
	}
	return false;
}

int main () {
	ori_L['N'-'A'][0] = 'N'; ori_L['N'-'A'][1] = 'W'; ori_L['N'-'A'][2] = 'S'; ori_L['N'-'A'][3] = 'E';
	ori_L['E'-'A'][0] = 'E'; ori_L['E'-'A'][1] = 'N'; ori_L['E'-'A'][2] = 'W'; ori_L['E'-'A'][3] = 'S';
	ori_L['S'-'A'][0] = 'S'; ori_L['S'-'A'][1] = 'E'; ori_L['S'-'A'][2] = 'N'; ori_L['S'-'A'][3] = 'W';
	ori_L['W'-'A'][0] = 'W'; ori_L['W'-'A'][1] = 'S'; ori_L['W'-'A'][2] = 'E'; ori_L['W'-'A'][3] = 'N';

	ori_R['N'-'A'][0] = 'N'; ori_R['N'-'A'][1] = 'E'; ori_R['N'-'A'][2] = 'S'; ori_R['N'-'A'][3] = 'W';
	ori_R['E'-'A'][0] = 'E'; ori_R['E'-'A'][1] = 'S'; ori_R['E'-'A'][2] = 'W'; ori_R['E'-'A'][3] = 'N';
	ori_R['S'-'A'][0] = 'S'; ori_R['S'-'A'][1] = 'W'; ori_R['S'-'A'][2] = 'N'; ori_R['S'-'A'][3] = 'E';
	ori_R['W'-'A'][0] = 'W'; ori_R['W'-'A'][1] = 'N'; ori_R['W'-'A'][2] = 'E'; ori_R['W'-'A'][3] = 'S';

	cin >> K;
	while(K--) {
		cin >> A >> B >> n >> m;
		for(int i = 1; i <= n; i++) {
			int x, y;
			char ch;
			cin >> x >> y >> ch;
			Robot r(i, x, y, ch);
			robot[i] = r;
		}
		bool flag = false;
		for(int i = 0; i < m; i++) {
			int curId, t;
			char ch;
			cin >> curId >> ch >> t;
			if(flag) continue;

			if(ch == 'F') {
				char ori = robot[curId].orientation;
				while(t--) {  // 每走一步都要检测是否发生碰撞
					if(ori == 'N') {
						robot[curId].y = robot[curId].y + 1;
					}
					else if(ori == 'E') {
						robot[curId].x = robot[curId].x + 1;
					}
					else if(ori == 'S') {
						robot[curId].y = robot[curId].y - 1;
					}
					else if(ori == 'W') {
						robot[curId].x = robot[curId].x - 1;
					}
					flag = over(curId);
					if(flag) break;
				}
			}
			else {
				int time = t % 4;
				if(ch == 'L') robot[curId].orientation = ori_L[robot[curId].orientation - 'A'][time];
				else if(ch == 'R') robot[curId].orientation = ori_R[robot[curId].orientation - 'A'][time];
			}
		}
		if(!flag) cout << "OK\n";
	}
}