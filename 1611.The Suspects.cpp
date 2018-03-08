#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

#define N 30010

/* 并查集 */
int group[N], father[N];

int find(int x) {
	if(x == father[x]) return x;
	else return father[x] = find(father[x]);
}

int main () {
	int n, m;
	while(cin >> n >> m) {
		if(!n && !m) break;
		for(int i = 0; i < n; i++) father[i] = i;
		for(int i = 0; i < m; i++) {
			int k;
			cin >> k;
			for(int j = 0; j < k; j++) {
				cin >> group[j];
			}
			for(int j = 1; j < k; j++) {
				int root1 = find(group[0]);
				int root2 = find(group[j]);
				if(root1 != root2)
					father[root1] = root2;
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++) {
			if(find(i) == find(0)) {
				ans++;
			}
		}
		cout << ans << endl;
	}
}