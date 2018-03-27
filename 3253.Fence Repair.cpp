#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

/* Huffman-tree 优先队列优化版 */

int main () {
	long long ans = 0;
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int> > q;  // 从小到大排序
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.push(x);
	}
	while(q.size() > 1) {
		int node1 = q.top();
		q.pop();
		int node2 = q.top();
		q.pop();
		int tmp = node1 + node2;
		ans += (tmp);
		q.push(tmp);
	}
	if(n == 1) ans = q.top();
	cout << ans << endl;
}