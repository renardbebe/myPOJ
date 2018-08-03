#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define N 510
#define INF 0x3f3f3f3f

int n, maxLen;
int road[N][N], visit[N], dis[N];

inline void prim() {
	memset(visit, 0, sizeof(visit));
	memset(dis, INF, sizeof(dis));
	for(int i = 1; i <= n; i++)
		dis[i] = road[1][i];
	visit[1] = 1;

	for(int i = 1; i < n; i++) {
		int minn = INF, pos = 0;
		for(int j = 1; j <= n; j++) {
			if(!visit[j] && dis[j] < minn) {
				minn = dis[j];
				pos = j;
			}
		}
		visit[pos] = 1;
		maxLen = max(maxLen, minn);
		// update
		for(int j = 1; j <= n; j++) {
			if(!visit[j] && road[pos][j] < dis[j]) {
				dis[j] = road[pos][j];
			}
		}
	}
}

int main () {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				scanf("%d", &road[i][j]);
			}
		}
		maxLen = 0;
		prim();
		printf("%d\n", maxLen);
	}
}