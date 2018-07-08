#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define N 2010
#define INF 0x3ffffff

int n;
string a[N];
int cost[N][N];
int visit[N], dis[N];

void calDis() {
	memset(cost, 0, sizeof(cost));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) {  // 减少遍历时间
			string s1 = a[i];
			string s2 = a[j];
			int len = s1.length();
			int d = 0;
			for(int i = 0; i < len; i++) {
				if(s1[i] != s2[i]) {
					d++;
				}
			}
			cost[i][j] = cost[j][i] = d;
		}
	}
}

void prim() {
	for(int i = 0; i < n; i++) {
		dis[i] = cost[0][i];
	}
	visit[0] = 1;
	int len = 0;
	for(int k = 1; k < n; k++) {
		int minn = INF, pos = 0;
		for(int i = 0; i < n; i++) {
			if(!visit[i] && dis[i] < minn) {
				minn = dis[i];
				pos = i;
			}
		}
		visit[pos] = 1;
		len += dis[pos];
		for(int i = 0; i < n; i++) {
			if(!visit[i] && dis[i] > cost[pos][i]) {
				dis[i] = cost[pos][i];
			}
		}
	}
	printf("The highest possible quality is 1/%d.\n", len);
}

int main () {
	while(cin >> n && n) {
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}

		calDis();
		memset(visit, 0, sizeof(visit));
		memset(dis, INF, sizeof(dis));
		prim();
	}
}