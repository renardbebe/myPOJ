#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
using namespace std;

#define N 20010

priority_queue<int, vector<int>, greater<int> > q;

int main () {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.push(x);
	}
	long long total = 0;  // long long !
	while(!q.empty()) {
		int node1 = q.top();
		q.pop();
		if(!q.empty()) {
			int node2 = q.top();
			q.pop();
			q.push(node1+node2);
			total += node1 + node2;
		}
	}
	cout << total << endl;
	system("pause");
}