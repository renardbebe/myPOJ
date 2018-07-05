#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

int n, m, in[26], tmp[26];
vector<int> adj[26];
vector<int> result;
queue<int> q;

void init() {
	memset(in, 0, sizeof(in));
	for(int i = 0; i < 26; i++) {
		adj[i].clear();
	}
}

int topoSort() {
	while(!q.empty()) q.pop();
	result.clear();

	for(int i = 0; i < n; i++) {
		if(in[i] == 0) {
			q.push(i);
		}
	}

	bool multi = false;
	while(!q.empty()) {
		if(q.size() > 1) {
			multi = true;
			//break;
		}
		int head = q.front();
		q.pop();
		result.push_back(head);
		for(int i = 0; i < adj[head].size(); i++) {
			in[adj[head][i]]--;
			if(in[adj[head][i]] == 0) q.push(adj[head][i]);
		}
	}

	if(result.size() < n) return 2;  // 有环
	if(multi) return 1;  // 有多种拓扑
	return 3;
}

int main () {
	while(cin >> n >> m) {
		if(!n && !m) break;

		init();
		bool find = false;
		int ret, pos = 0;
		for(int i = 0; i < m; i++) {
			char ch1, op, ch2;
			cin >> ch1 >> op >> ch2;
			if(find) continue;

			in[ch2 - 'A']++;
			adj[ch1 - 'A'].push_back(ch2 - 'A');
			memcpy(tmp, in, sizeof(in));
			ret = topoSort();
			if(ret != 1) {  // 有环或已确定拓扑顺序
				find = true;
				pos = i+1;
			}
			memcpy(in, tmp, sizeof(tmp));
		}

		if(ret == 1)
			printf("Sorted sequence cannot be determined.\n");
		else if(ret == 2)
			printf("Inconsistency found after %d relations.\n", pos);
		else {
			printf("Sorted sequence determined after %d relations: ", pos);
			for(int i = 0; i < n; i++) {
				printf("%c", result[i] + 'A');
			}
			printf(".\n");
		}
	}
}