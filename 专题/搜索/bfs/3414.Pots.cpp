#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

#define N 110

int A, B, C;
int visit[N][N];  // 记录当前状态有没有到达过

struct OP
{
	int id;
	int V1, V2;
	int step;
	vector<int> path;
	OP() {}
	OP(int i, int a, int b, int s, vector<int> p) {
		id = i; V1 = a; V2 = b; step = s; path = p;
	}
};

void bfs() {
	memset(visit, 0, sizeof(visit));
	queue<OP> q;
	vector<int> v;

	OP op(0, 0, 0, 0, v);
	q.push(op);
	visit[0][0] = 1;

	while(!q.empty()) {
		OP head = q.front();
		q.pop();
		if(head.V1 == C || head.V2 == C) {
			cout << head.step << endl;
			for(vector<int>::iterator it = head.path.begin(); it != head.path.end(); it++) {
				if(*it == 1) cout << "FILL(1)" << endl;
				else if(*it == 2) cout << "FILL(2)" << endl;
				else if(*it == 3) cout << "DROP(1)" << endl;
				else if(*it == 4) cout << "DROP(2)" << endl;
				else if(*it == 5) cout << "POUR(2,1)" << endl;
				else if(*it == 6) cout << "POUR(1,2)" << endl;
			}
			return;
		}

		for(int i = 1; i <= 6; i++) {
			OP tmp;
			tmp.id = i;
			tmp.step = head.step+1;
			tmp.path = head.path;
			switch(i) {
				case 1 : {
					tmp.V1 = A;
					tmp.V2 = head.V2;
					break;
				}
				case 2 : {
					tmp.V1 = head.V1;
					tmp.V2 = B;
					break;
				}
				case 3 : {
					tmp.V1 = 0;
					tmp.V2 = head.V2;
					break;
				}
				case 4 : {
					tmp.V1 = head.V1;
					tmp.V2 = 0;
					break;
				}
				case 5 : {
					int left = A - head.V1;
					if(left > head.V2) {
						tmp.V1 = head.V1 + head.V2;
						tmp.V2 = 0;
					}
					else {
						tmp.V1 = A;
						tmp.V2 = head.V2 - left;
					}
					break;
				}
				case 6 : {
					int left = B - head.V2;
					if(left > head.V1) {
						tmp.V1 = 0;
						tmp.V2 = head.V2 + head.V1;
					}
					else {
						tmp.V1 = head.V1 - left;
						tmp.V2 = B;
					}
					break;
				}
			}
			if(visit[tmp.V1][tmp.V2]) continue;
			visit[tmp.V1][tmp.V2] = 1;
			tmp.path.push_back(i);
			q.push(tmp);
		}
	}
	cout << "impossible\n";
}

int main () {
	cin >> A >> B >> C;
	bfs();
	system("pause");
}