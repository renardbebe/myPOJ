#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

/* 判断是否存在负环
   Bellman_Ford算法

   题意：农夫的花园里有条路和个虫洞，每条路有时间开销，虫洞可以使时光倒流
   问他能否从一个点经过一系列的路径和虫洞后，在这个点遇到从前的自己

   路是双向的，虫洞是单向的，存路的数组需要 2*MAX_E + MAX_W
 */

#define INF 999999
#define MAX_V 505
#define MAX_E 5205

struct Edge
{
	int start;
	int end;
	int weight;
};

Edge edge[MAX_E];
int dis[MAX_V];  // 记录两个顶点之间的距离
int E, V;

bool Bellman_Ford(int s) {
	for(int i = 1; i <= V; i++) dis[i] = ((i == s) ? 0 : INF);
	for(int i = 1; i <= V; i++) {  // 对所有边松弛|V|-1次，第V次循环检查负权回路
		for(int j = 0; j < E; j++) {
			Edge e = edge[j];
			if(dis[e.end] > dis[e.start] + e.weight) {
				dis[e.end] = dis[e.start] + e.weight;
				if(i == V) return true;
			}
		}
	}
	return false;
}

int main () {
	int T;
	cin >> T;
	while(T--) {
		int n, m ,w;
		cin >> n >> m >> w;
		V = n;
		E = 0;
		for(int i = 0; i < m; i++) {  // 输入路径
			int s, e, cost;
			cin >> s >> e >> cost;
			edge[E].start = s;
			edge[E].end = e;
			edge[E++].weight = cost;
			edge[E].start = e;
			edge[E].end = s;
			edge[E++].weight = cost;
		}
		for(int i = 0; i < w; i++) {  // 输入虫洞
			int s, e, cost;
			cin >> s >> e >> cost;
			edge[E].start = s;
			edge[E].end = e;
			edge[E++].weight = -cost;
		}
		bool flag = Bellman_Ford(1);
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}