#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int n, m;
int visit[10000];
bool flag;

struct Node
{
	int num;
	int step;
	Node() {}
	Node(int n, int s) {
		num = n; step = s;
	}
};

bool isprime(int x) {
	if(x < 2) return false;
	for(int i = 2; i <= sqrt(double(x)); i++) {
		if(x % i == 0)
			return false;
	}
	return true;
}

void bfs() {
	memset(visit, 0, sizeof(visit));
	flag = false;

	queue<Node> q;
	Node node(n, 0);
	q.push(node);
	visit[n] = 1;

	while(!q.empty()) {
		Node head = q.front();
		q.pop();
		for(int i = 0; i <= 9; i++) {  // 个位
			if(i%2 == 0) continue;  // 不可能为偶数
			int num = head.num / 10 * 10 + i;
			if(!visit[num] && isprime(num)) {
				if(num == m) {
					cout << head.step+1 << endl;
					flag = true;
					return;
				}
				else {
					Node tmp(num, head.step+1);
					q.push(tmp);
					visit[num] = 1;
				}
			}
		}
		for(int i = 0; i <= 9; i++) {  // 十位
			int num = head.num / 100 * 100 + i * 10 + head.num % 10;
			if(!visit[num] && isprime(num)) {
				if(num == m) {
					cout << head.step+1 << endl;
					flag = true;
					return;
				}
				else {
					Node tmp(num, head.step+1);
					q.push(tmp);
					visit[num] = 1;
				}
			}
		}
		for(int i = 0; i <= 9; i++) {  // 百位
			int num = head.num / 1000 * 1000 + i * 100 + head.num % 100;
			if(!visit[num] && isprime(num)) {
				if(num == m) {
					cout << head.step+1 << endl;
					flag = true;
					return;
				}
				else {
					Node tmp(num, head.step+1);
					q.push(tmp);
					visit[num] = 1;
				}
			}
		}
		for(int i = 1; i <= 9; i++) {  // 千位
			int num = i * 1000 + head.num % 1000;
			if(!visit[num] && isprime(num)) {
				if(num == m) {
					cout << head.step+1 << endl;
					flag = true;
					return;
				}
				else {
					Node tmp(num, head.step+1);
					q.push(tmp);
					visit[num] = 1;
				}
			}
		}
	}
}

int main () {
	int T;
	cin >>T;
	while(T--) {
		cin >> n >> m;
		if(n == m) {
			cout << 0 << endl;
			continue;
		}
		bfs();
		if(!flag) cout << "Impossible\n";
	}
}