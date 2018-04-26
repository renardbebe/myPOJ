#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define N 1010
#define INF 999999
int road[N][N];
int dis1[N][N], dis2[N][N];
int visit[N];
int n, m, x;

/* 2次最短路 */

void init() {
	for(int i = 1; i < N; i++) {
		for(int j = 1; j < N; j++)
			road[i][j] = INF;
	}
}

void dijkstra() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) {
				dis1[i][j] = dis2[i][j] = 0;
			}
			else {
				dis1[i][j] = road[j][i];
				dis2[i][j] = road[i][j];
			}
		}
	}
	// 去
	memset(visit, 0, sizeof(visit));
	for(int k = 1; k < n; k++) {
		int pos = 0, minn = INF;
		for(int i = 1; i <= n; i++) {
			if(!visit[i] && dis1[x][i] < minn) {
				pos = i;
				minn = dis1[x][i];
			}
		}
		visit[pos] = 1;
		for(int i = 1; i <= n; i++) {
			if(!visit[i]) {
				dis1[x][i] = min(dis1[x][i], dis1[x][pos] + dis1[pos][i]);
			}
		}
	}
	// 回
	memset(visit, 0, sizeof(visit));
	for(int k = 1; k < n; k++) {
		int pos = 0, minn = INF;
		for(int i = 1; i <= n; i++) {
			if(!visit[i] && dis2[x][i] < minn) {
				pos = i;
				minn = dis2[x][i];
			}
		}
		visit[pos] = 1;
		for(int i = 1; i <= n; i++) {
			if(!visit[i]) {
				dis2[x][i] = min(dis2[x][i], dis2[x][pos] + dis2[pos][i]);
			}
		}
	}
}

int main () {
	init();
	cin >> n >> m >> x;
	for(int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		road[a][b] = t;
	}
	dijkstra();
	int maxLen = 0;
	for(int i = 1; i <= n; i++) {
		int tmp = dis1[x][i] + dis2[x][i];
		maxLen = max(maxLen, tmp);
	}
	cout << maxLen << endl;
	while(1);
}