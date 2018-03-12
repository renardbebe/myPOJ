#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

#define N 1005
#define INF 999999

int t, n;
int land[N][N];
int visit[N], dis[N];

void dijkstra() {
	for(int i = 1; i <= n; i++) dis[i] = (i==1) ? 0 : INF;

	for(int j = 1; j <= n; j++) {
		int minn = INF, pos = 0;
		for(int i = 1; i <= n; i++) {
			if(!visit[i] && dis[i] < minn) {
				minn = dis[i];
				pos = i;
			}
		}
		visit[pos] = 1;
		// update other vertexs
		for(int i = 1; i <= n; i++) {
			if(!visit[i] && dis[i] > dis[pos] + land[pos][i])
				dis[i] = dis[pos] + land[pos][i];
		}
	}
}

int main () {
	cin >> t >> n;
	memset(visit, 0, sizeof(visit));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) land[i][j] = 0;
			else land[i][j] = land[j][i] = INF;
		}
	}

	for(int i = 0; i < t; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		if(land[x][y] > w)  // 可能有多重边
			land[x][y] = land[y][x] = w;
	}
	dijkstra();
	cout << dis[n] << endl;
}