#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 30
#define INF 0x3f3f3f3f
int n, road[N][N], visit[N], dis[N];

inline void prim() {
	for(int i = 1; i <= n; i++) {
		dis[i] = road[i][1];
	}
	memset(visit, 0, sizeof(visit));
	visit[1] = 1;

	int ret = 0;
	for(int i = 1; i < n; i++) {
		int minn = INF, pos = 0;
		for(int j = 1; j <= n; j++) {
			if(!visit[j] && dis[j] < minn) {
				minn = dis[j];
				pos = j;
			}
		}
		visit[pos] = 1;
		ret += minn;

		for(int j = 1; j  <= n; j++) {
			if(!visit[j] && dis[j] > road[pos][j])
				dis[j] = road[pos][j];
		}
	}
	cout << ret << endl;
}

int main () {
	while(cin >> n && n) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++)
				road[i][j] = i == j ? 0 : INF;
		}
		for(int i = 1; i < n; i++) {
			char node;
			int num;
			cin >> node >> num;
			for(int j = 1; j <= num; j++) {
				char x;
				int d;
				cin >> x >> d;
				road[x - 'A' + 1][node - 'A' + 1] = road[node - 'A' + 1][x - 'A' + 1] = d;
			}
		}
		prim();
	}
}