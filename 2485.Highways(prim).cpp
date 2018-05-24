#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 510
#define INF 999999
int graph[N][N], dis[N], visit[N], n;

/* 最小生成树中的最大边 prim / kruskal */

int prim() {
	for(int i = 0; i < n; i++)
		dis[i] = graph[0][i];  // 记录最小生成树顶点集合到其他每个点的距离
	visit[0] = 1;
	int max_len = 0;
	for(int i = 0; i < n-1; i++) {  // 选择n-1条边
		int pos = -1;
		int minn = INF;
		for(int j = 0; j < n; j++) {
			if(!visit[j] && dis[j] < minn) {
				minn = dis[j];
				pos = j;
			}
		}
		visit[pos] = 1;
		max_len = max(minn, max_len);
		// 更新距离
		for(int j = 0; j < n; j++) {
			if(!visit[j] && dis[j] > graph[pos][j])
				dis[j] = graph[pos][j];
		}
	}
	return max_len;
}

int main () {
	int T;
	scanf("%d", &T);
	while(T--) {
		memset(visit, 0, sizeof(visit));
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++)
				scanf("%d", &graph[i][j]);
		}
		printf("%d\n", prim());
	}
}