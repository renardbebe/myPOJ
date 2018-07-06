#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

#define N 250
#define INF 0x3f3f3f3f

int n;
struct Node
{
	double x, y;
} node[N];

double stone[N][N];
double dis[N];
int visit[N];

/* 最短路中最长的一条 */

void dij() {
	double ans = 0.0;
	memset(dis, INF, sizeof(dis));
	memset(visit, 0, sizeof(visit));
	for(int i = 0; i < n; i++)
		dis[i] = stone[0][i];
	visit[0] = 1;

	for(int i = 0; i < n-1; i++) {
		double minn = 1.0*INF;
		int pos = 0;
		for(int j = 0; j < n; j++) {
			if(!visit[j] && dis[j] < minn) {
				minn = dis[pos = j];
			}
		}
		visit[pos] = 1;

		// update
		if(minn > ans) ans = minn;
		if(pos == 1) break;

		for(int j = 0; j < n; j++) {
			if(!visit[j] && dis[j] > stone[pos][j]) {
				dis[j] = stone[pos][j];
			}
		}
	}
	printf("Frog Distance = %.3lf\n\n", ans);
}

int main () {
	int kase = 1;
	while(~scanf("%d", &n) && n) {
		printf("Scenario #%d\n", kase++);
		for(int i = 0; i < n; i++) {
			scanf("%lf%lf", &node[i].x, &node[i].y);
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++)
				stone[i][j] = stone[j][i] = sqrt(pow((node[i].x - node[j].x), 2) + pow((node[i].y - node[j].y), 2));
		}
		dij();
	}
}