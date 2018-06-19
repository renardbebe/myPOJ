#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
using namespace std;

/* 贪心 */

#define N 1010
#define M 5010
set<string> ip;
string destination[M];

int main () {
	int n, m;
	while(cin >> n) {
		ip.clear();
		for(int i = 0; i < n; i++) {
			string tmp;
			cin >> tmp;
			ip.insert(tmp);
		}
		cin >> m;
		for(int j = 0; j < m; j++) {
			cin >> destination[j];
		}
		if(n == 1) {  // 只有一个代理服务器
			for(int j = 0; j < m; j++) {
				if(destination[j] == *(ip.begin())) {  // 只有一个且存在冲突
					cout << -1 << endl;
					break;
				}
				else if(j == m-1) {
					cout << 0 << endl;
				}
			}
		}
		else {
			int s = 0;
			set<string> visit;
			for(int i = 0; i < m; i++) {
				if(ip.find(destination[i]) != ip.end()) {  // 若有冲突
					visit.insert(destination[i]);
					if(visit.size() == n) {
						s++;
						visit.clear();
						visit.insert(destination[i]);  // !!发生冲突时使用的ip（区间内最长无冲突）
					}
				}
			}
			// set<string> avail(ip);
			// for(int i = 0; i < m; i++) {
			// 	if(avail.count(destination[i]) != NULL) {  // 发生冲突
			// 		avail.erase(destination[i]);
			// 		if(avail.size() == 0) {  // 无法避免，必须切换代理
			// 			s++;
			// 			avail = ip;
			// 			avail.erase(destination[i]);  // 后续可选择代理中不包括冲突ip
			// 		}
			// 	}
			// }
			cout << s << endl;
		}
	}
}