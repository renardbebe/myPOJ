#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

#define N 70

/*
  dfs + 剪枝

  求出总长度sum和小棒最长的长度max，则原棒可能的长度必在max~sum之间，
  然后从小到大枚举max~sum之间能被sum整除的长度len，
  用dfs求出所有的小棒能否拼凑成这个长度，如果可以，第一个len就是答案
*/

int n, len, stick[N];
bool flag, visit[N];

bool cmp(const int& a, const int& b) {
	return (a>b);
}

void dfs(int used, int now_len, int u) {  // used:当前已使用过的小棒数 now_len:当前长度 u: 当前要处理的小棒
	if(flag) return;
	if(now_len == 0) {  // 从当前未使用的最长的小棒开始拼接
		int k = 0;
		while(visit[k]) k++;
		visit[k] = true;
		dfs(used+1, now_len+stick[k], k+1);
		visit[k] = false;
		return;
	}
	else if(now_len == len) {  // 当前长度为len，即又拼凑成了一根原棒
		if(used == n) flag = true;  // 所有小棒都完成了拼接
		else dfs(used, 0, 0);
		return;
	}
	else {
		for(int i = u; i < n; i++) {
			if(!visit[i] && (now_len + stick[i]) <= len) {
				if(!visit[i-1] && stick[i] == stick[i-1]) // 剪枝: 同样长度的小棒不重复搜索
					continue;
				visit[i] = true;
				dfs(used+1, now_len+stick[i], i+1);
				visit[i] = false;
			}
		}
	}
}

int main () {
	while(cin >> n && n) {
		int sum = 0;
		flag = false;
		for(int i = 0; i < n; i++) {
			cin >> stick[i];
			sum += stick[i];
		}
		sort(stick, stick+n, cmp);  // 从大到小排序
		for(len = stick[0]; len <= sum; len++) {
			if((sum % len) == 0) {
				memset(visit,false,sizeof(visit));
				dfs(0, 0, 0);
				if(flag) break;
			}
		}
		cout << len << endl;
	}
}