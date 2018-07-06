#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

/* prim 最小生成树 */

#define N 30
#define INF 0x3f3f3f3f

int n;
int road[N][N], dis[N];
bool visit[N];

int prim () {
	for(int i = 0; i < n; i++) {
		dis[i] = road[0][i];
		visit[i] = false;
	}
	visit[0] = true;
	for(int i = 1; i < n; i++) {  // 依次选取n-1个顶点
		int d = INF, pos = 0;
		for(int j = 0; j < n; j++) {  // 遍历n个顶点, 每次选择不在已选集合内的最短边顶点
			if(!visit[j] && dis[j] < d) {
				d = dis[j];
				pos = j;
			}
		}
		visit[pos] = true;
		// update
		for(int j = 0; j < n; j++) {
			if(!visit[j] && dis[j] > road[pos][j])
				dis[j] = road[pos][j];
		}
	}
	int len = 0;
	for(int i = 0; i < n; i++)
		len += dis[i];
	return len;
}

int main () {
	while(cin >> n && n) {
		memset(road, INF, sizeof(road));
		for(int i = 0; i < n; i++)
			road[i][i] = 0;
		for(int i = 0; i < n-1; i++) {
			char node, child;
			int num, w;
			cin >> node >> num;
			for(int j = 0; j < num; j++) {
				cin >> child >> w;
				road[node - 'A'][child - 'A'] = road[child - 'A'][node - 'A'] = w;
			}
		}
		cout << prim() << endl;
	}
}