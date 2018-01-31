#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

#define N 120
#define INF 999999
int n, matrix[N][N], m;

void floyd() {
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(matrix[i][j] > matrix[i][k] + matrix[k][j])
					matrix[i][j] = matrix[i][k] + matrix[k][j];
}

int main () {
	while(cin >> n && n) {
		memset(matrix, INF, sizeof(matrix));
		for(int i = 1; i <= n; i++) {
			cin >> m;
			matrix[i][i] = 0;
			while(m--) {
				int x, d;
				cin >> x >> d;
				matrix[i][x] = d;
			}
		}
		floyd();

		int minn = INF, maxn, index;
		for(int i = 1; i <= n; i++) {
			maxn = 0;  // 记录最长接收时间
			for(int j = 1; j <= n; j++) {
				maxn = max(maxn, matrix[i][j]);
			}
			if(maxn < minn) {
				minn = maxn;
				index = i;
			}
		}
		if(minn == INF) printf("disjoint\n");
		else printf("%d %d\n", index, minn);
	}
}