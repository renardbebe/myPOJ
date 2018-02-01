#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define N 200100
bool visit[N];  // 避免重复访问已考虑过的位置，超时

struct Node
{
	int pos;
	int step;
	Node() {}
	Node(int p, int s) {
		pos = p;
		step = s;
	}
};

int bfs(int start, int end) {
	memset(visit,false,sizeof(visit));
	queue<Node> q;
	Node a(start, 0);
	q.push(a);
	visit[start] = true;
	while(!q.empty()) {
		Node head = q.front();
		q.pop();
		if(head.pos == end) {
			return head.step;
		}
		if(head.pos >= 1 && !visit[head.pos-1]) {
			q.push(Node(head.pos-1, head.step+1));
			visit[head.pos-1] = true;
		}
		if(head.pos <= end && !visit[head.pos+1]) {
			q.push(Node(head.pos+1, head.step+1));
			visit[head.pos+1] = true;
		}
		if(head.pos <= end && !visit[2*head.pos]) {
			q.push(Node(2*head.pos, head.step+1));
			visit[2*head.pos] = true;
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << bfs(n, k) << endl;
	system("pause");
}