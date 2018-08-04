#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

#define N 15

/* 求 n 个字符串的最长公共子序列 */

string a[N];

int main () {
	int T, m;
	cin >> T;
	while(T--) {
		cin >> m;
		for(int i = 0; i < m; i++) {
			cin >> a[i];
		}
		sort(a, a+m);
		int len = a[0].length();

		string result = "";
		int maxLen = 0;
		for(int l = 3; l <= len; l++) {  // 枚举长度
			for(int i = 0; i+l <= len; i++) {  // 枚举起始位置
				string tmp = a[0].substr(i, l);
				bool flag = true;
				for(int j = 1; j < m; j++) {
					if(a[j].find(tmp) == a[j].npos) {
						flag = false;
						break;
					}
				}
				if(flag) {
					if(l > maxLen) {
						maxLen = l;
						result = tmp;
					}
					else if(l == maxLen) {
						if(result > tmp) result = tmp;  // 字典序最小的
					}
				}
			}
		}

		if(result == "") cout << "no significant commonalities\n";
		else {
			cout << result << endl;
		}
	}
	system("pause");
}