// 最小堆

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int main () {
	int n, type, u;
	cin >> n;
	priority_queue<int, vector<int>, greater<int> > minheap;
	for(int i = 0; i < n; i++) {
		cin >> type;
		if(type == 1) {
			cin >> u;
			minheap.push(u);
		}
		else {
			cout << minheap.top() << endl;
			minheap.pop();
		}
	}
}