#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;

#define N 1010
int father[N], visit[N];

inline int find(int x) {
	if(father[x] == x) return x;
	else return father[x] = find(father[x]);
}

int main () {
	int T, n, m;
	cin >> T;
	while(T--) {
		cin >> n >> m;
		for(int i = 1; i <= n; i++) father[i] = i;
		for(int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			int root1 = find(x), root2 = find(y);
			if(root1 != root2) {
				father[root1] = root2;
			}
		}
		int cnt = 0;
		memset(visit, 0, sizeof(visit));
		for(int i = 1; i <= n; i++) {
			if(!visit[find(i)]) {
				visit[find(i)] = 1;
				cnt++;
			}
		}
		cout << cnt << endl;
	}
}