#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 10005;

/* LCA 模板题 */

int father[maxn], node1, node2, ans;
bool visit[maxn], root[maxn];
vector<int> child[maxn];

int find(int x) {
	if(x == father[x]) return x;
	else return father[x] = find(father[x]);
}

void merge(int n1, int n2) {
	int root1 = find(n1);
	int root2 = find(n2);
	father[root1] = root2;
}

void LCA(int root) {
	visit[root] = true;
	father[root] = root;
	// 找每个结点的最近公共祖先
	for(int i = 0; i < child[root].size(); i++) {
		LCA(child[root][i]);
		merge(child[root][i], root);
	}

	// 基于后序遍历，LCA一定是先访问过的结点的祖先
	if(root == node1 && visit[node2]) {
		ans = find(node2);
		return;
	}
	if(root == node2 && visit[node1]) {
		ans = find(node1);
		return;
	}
}

int main () {
	int T, n;
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1; i <= n; i++) {  // n个点
			root[i] = true;
			visit[i] = false;
			child[i].clear();
		}
		for(int i = 1; i < n; i++) {  // n-1条边
			int a, b;
			cin >> a >> b;
			child[a].push_back(b);
			root[b] = false;
		}
		cin >> node1 >> node2;
		for(int i = 1; i <= n; i++) {
			if(root[i]) {  // 找根
				LCA(i);
				break;
			}
		}
		cout << ans << endl;
	}
}