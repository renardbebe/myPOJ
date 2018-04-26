#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

struct Node
{
	int id;
	int level;
	Node(){}
	Node(int i, int l) {
		id = i;
		level = l;
	}
};

deque<Node> q;

int main () {
	int query;
	while(cin >> query) {
		if(query == 0) break;
		if(query == 1) {
			int k, p;
			cin >> k >> p;
			Node node(k, p);
			// 维护一个最大值优先队列
			if(q.empty()) q.push_back(node);
			else {
				bool flag = false;
				for(deque<Node>::iterator it = q.begin(); it != q.end(); it++) {
					if(p > (*it).level) {
						q.insert(it, node);
						flag = true;
						break;
					}
				}
				if(!flag) q.push_back(node);
			}
		}
		else if(query == 2) {
			if(q.empty()) cout << 0 << endl;
			else {
				cout << q.front().id << endl;
				q.pop_front();
			}
		}
		else if(query == 3) {
			if(q.empty()) cout << 0 << endl;
			else {
				cout << q.back().id << endl;
				q.pop_back();
			}
		}
	}
}