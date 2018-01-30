#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

#define N 105
#define INF 999999

int matrix[N][N];
bool visit[N];
int min_dis[N];  // 记录到当前结点集合的最短距离

/* prim 最小生出树 */

int prime(int cur, int n) {  // cur: 当前node
	int sum = 0, index;
	memset(visit, false, sizeof(visit));
	visit[cur] = true;
	for(int i = 0; i < n; i++)
		min_dis[i] = matrix[cur][i];  // 初始化
	for(int edge = 1; edge < n; edge++) {  // 选取n-1条边
		int minn = INF;
		for(int j = 0; j < n; j++) {  // 选择当前相连的最短边
			if(!visit[j] && min_dis[j] < minn) {
				minn = min_dis[j];
				index = j;
			}
		}

		visit[index] = true;
		sum += minn;

		for(int j = 0; j < n; j++) {  // 更新其他结点到当前结点集合的距离
			if(!visit[j] && min_dis[j] > matrix[index][j]) {
				min_dis[j] = matrix[index][j];
			}
		}
	}
	return sum;
}

int main () {
	int n;
	while(cin >> n) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		cout << prime(0, n) << endl;
	}
}