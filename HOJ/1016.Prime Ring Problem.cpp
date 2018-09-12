#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

#define N 100
int n, tmp[N], visit[N];
set<int> prime = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};  // maxn prime sum

inline bool check() {
	for(int i = 0; i < n; i++) {
		int sum;
		if(i == n-1) {
			sum = tmp[i] + tmp[0];
		}
		else {
			sum = tmp[i] + tmp[i+1];
		}
		if(prime.find(sum) == prime.end()) return false;
	}
	return true;
}

inline void dfs(int cur) {
	if(cur == n) {
		if(prime.find(tmp[0] + tmp[n-1]) != prime.end()) {
			for(int i = 0; i < n; i++) {
				if(i) cout << " " << tmp[i];
					else cout << tmp[i];
			}
			cout << endl;
		}
		return;
	}

	for(int i = 2; i <= n; i++) {
		if(!visit[i] && prime.find(i + tmp[cur-1]) != prime.end()) {  // 剪枝
			visit[i] = 1;
			tmp[cur] = i;
			dfs(cur+1);
			visit[i] = 0;
		}
	}
}

int main () {
	int kase = 1;
	while(cin >> n) {
		if(kase != 1) cout << endl;
		cout << "Case " << kase++ << ":" << endl;
		if(n == 1) {
			cout << 1 << endl;
			continue;
		}
		memset(visit, 0, sizeof(visit));
		tmp[0] = 1;  // 以 1 开头的素数环
		dfs(1);
	}
}