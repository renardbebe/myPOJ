#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

#define N 2020

/* 种类并查集 */
int n, m;
int father[N], opp[N], rank_[N];  // opp: 每只虫子的配偶 rank_: 按秩合并

void init() {
	for(int i = 1; i <= n; i++)
		father[i] = i;
	memset(opp, 0, sizeof(opp));
	memset(rank_, 0, sizeof(rank_));
}

int find(int x) {
	if(x == father[x]) return x;
	else return father[x] = find(father[x]);
}

void unionset(int x, int y) {
	int root1 = find(x);
	int root2 = find(y);
	if(root1 == root2) return;
	if(root1 < root2) {
		father[root1] = root2;
	}
	else father[root2] = root1;
	// 优化：按秩合并
	// if(rank_[root1] < rank_[root2]) {
	// 	father[root1] = root2;
	// }
	// else {
	// 	father[root2] = root1;
	// 	if(rank_[root1] == rank_[root2])
	// 		rank_[root1]++;
	// }
}

int main () {
	int T;
	cin >> T;
	for(int kase = 1; kase <= T; kase++) {
		scanf("%d%d", &n, &m);
		init();
		bool flag = false;
		for(int i = 0; i < m; i++) {
			int x, y;
			scanf("%d%d", &x, &y);

			if(flag) // 找到了同性恋的虫子
				continue;
			if(find(x) == find(y)) {
				flag = true;
			}
			else if(!opp[x] && !opp[y]) {
				opp[x] = y;
				opp[y] = x;
			}
			else if(opp[x] && !opp[y]) {  // x 有配偶
				opp[y] = x;
				unionset(y, opp[x]);
			}
			else if(!opp[x] && opp[y]) {  // y 有配偶
				opp[x] = y;
				unionset(x, opp[y]);
			}
			else {  // 都有配偶
				unionset(x, opp[y]);
				unionset(y, opp[x]);
			}
		}
		printf("Scenario #%d:\n", kase);
		if(flag) printf("Suspicious bugs found!\n");
		else printf("No suspicious bugs found!\n");
		printf("\n");
	}
}