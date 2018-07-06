#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 100

int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dy[8] = {-2, -2, -1, -1, 1, 1, 2, 2};

int path[N][N], visit[N][N];
int p, q;
bool flag;

bool in(int x, int y) {
	return (x >= 1 && x <= p && y >= 1 && y <= q);
}

void dfs(int row, int col, int step) {
	path[step][0] = row;
	path[step][1] = col;

	if(step == p*q) {
		flag = true;
		return;
	}
	for(int i = 0; i < 8; i++) {
		int next_r = row + dx[i];
		int next_c = col + dy[i];
		if(!flag && in(next_r, next_c) && !visit[next_r][next_c]) {
			visit[next_r][next_c] = 1;
			dfs(next_r, next_c, step+1);
			visit[next_r][next_c] = 0;
		}
	}
}

int main () {
	int n, kase = 1;
	cin >> n;
	while(n--) {
		flag = false;
		memset(visit, 0, sizeof(visit));
		cin >> p >> q;
		visit[1][1] = 1;
		dfs(1, 1, 1);
		printf("Scenario #%d:\n", kase++);
		if(flag) {
			for(int i = 1; i <= p*q; i++) {
				printf("%c%d", path[i][1] - 1 + 'A', path[i][0]);
			}
			printf("\n");
		}
		else printf("impossible\n");

		if(n) printf("\n");
	}
}