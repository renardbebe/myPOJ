#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <string>
using namespace std;

int n;
bool flag;

void dfs(int k, long long cur) {  // k:位数 cur:当前数字
	if(flag || k == 19) return;
	if(cur % n == 0) {
		flag = true;
		cout << cur << endl;
		return;
	}
	dfs(k+1, cur*10);    // 末尾为0
	dfs(k+1, cur*10+1);  // 末尾为1
}

int main () {
	while(cin >> n && n) {
		flag = false;
		dfs(0, 1);
	}
}