#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 1005
int father[N];

inline int find(int x) {
	if(father[x] == x) return x;
	else return father[x] = find(father[x]);
}

int main () {
	int n, m;
	while(scanf("%d", &n) && n) {
		scanf("%d", &m);
		for(int i = 1; i <= n; i++) father[i] = i;

		for(int i = 0; i < m; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			int root1 = find(x), root2 = find(y);
			if(root1 != root2) father[root1] = root2;
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			if(find(i) == i) cnt++;
		}
		printf("%d\n", cnt-1);
	}
}