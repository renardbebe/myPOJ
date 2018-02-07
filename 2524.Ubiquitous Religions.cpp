#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

#define N 50005

/* 并查集 */

int n, m;
int father[N];

int find(int x) {
	return (father[x] == x) ? x : father[x] = find(father[x]);
}

int main () {
	int kase = 1;
	while(cin >> n >> m && n && m) {
		int num = n;  // 记录不同信仰人数
		for(int i = 1; i <= n; i++) {
			father[i] = i;
		}
		for(int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			int root1 = find(a);
			int root2 = find(b);
			if(root1 != root2) {
				father[root1] = root2;
				num--;
			}
		}
		cout << "Case " << kase++ << ": " << num << endl;
	}
}