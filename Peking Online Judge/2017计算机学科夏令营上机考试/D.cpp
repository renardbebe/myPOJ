#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

int target;
char str[20];
string result;
bool flag;
int len;
bool visit[20];

bool cmp(const char &ch1, const char &ch2) {
	return ch1 > ch2;
}

void dfs(int result_len, string s) {
	if(flag) return;
	if(result_len == 5) {
		int tmp = (s[0] - 'A' + 1) - pow((s[1] - 'A' + 1), 2) + pow((s[2] - 'A' + 1), 3) - pow((s[3] - 'A' + 1), 4) + pow((s[4] - 'A' + 1), 5);
		if(tmp == target) {
			flag = true;
			result = s;
		}
		return;
	}

	for(int pos = 0; pos < len; pos++) {
		if(!visit[pos]) {
			visit[pos] = 1;
			dfs(result_len+1, s+str[pos]);
			visit[pos] = 0;
		}
	}
}

int main () {
	while(1) {
		cin >> target;
		getchar();
		gets(str);
		len = strlen(str);
		flag = false;
		memset(visit, 0, sizeof(visit));
		if(target == 0) break;
		result = "";
		sort(str, str+len, cmp);
		dfs(0, "");
		if(flag)
			cout << result << endl;
		else
			cout << "no solution" << endl;
	}
}