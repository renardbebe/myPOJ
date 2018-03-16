#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <stack>
#include <deque>
using namespace std;

int a[1001];

int main () {
	int n;
	while(cin >> n) {
		if(n == 0) break;
		while(1) {
			memset(a,0,sizeof(a));
			deque<int>q;
			stack<int>s;
			cin >> a[0];
			if(a[0] == 0) break;
			q.push_front(a[0]);
			for(int i = 1; i < n; i++) {
				cin >> a[i];
				q.push_front(a[i]);
			}
			for(int i = n; i >= 1;) {
				if(!q.empty() && q.front() == i) {
					q.pop_front();
					i--;
				}
				else if(!s.empty() && (s.top() == i)) {
					s.pop();
					i--;
				}
				else {
					if(!q.empty()) {
						s.push(q.front());
						q.pop_front();
					}
					else break;
				}
			}
			if(s.empty()) cout << "Yes\n";
			else cout << "No\n";
		}
		cout << endl;
	}
	return 0;
}
