#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

#define INF 999999

/* 贪心
   从左往右，如果按钮不匹配就按下一个按钮，
   始终让左面的按钮是匹配的，如果遍历到最后一个按钮不匹配则"impossible"

   对起始按钮不匹配的分两种情况讨论：1. 按第一个 2. 按第二个
*/

string s, target, t;
int len;

void flip(int pos) {
	if(pos > 0) s[pos-1] = s[pos-1] == '1' ? '0' : '1';
	s[pos] = s[pos] == '1' ? '0' : '1';
	if(pos < len-1) s[pos+1] = s[pos+1] == '1' ? '0' : '1';
}

int main () {
	cin >> s >> target;
	t = s;
	len = s.length();
	int step = INF, tmp = 0;
	// 始终翻第二个
	for(int i = 1; i < len; i++) {
		if(s[i-1] != target[i-1]) {
			flip(i);
			tmp++;
		}
	}
	if(s[n-1] == target[n-1]) step = tmp;
	// 在起始位置翻第一个
	tmp = 0;
	s = t;
	if(s[0] != target[0] || s[1] != target[1]) {
		flip(0);
		tmp++;
	}
	for(int i = 1; i < len; i++) {
		if(s[i-1] != target[i-1]) {
			flip(i);
			tmp++;
		}
	}
	if(s[n-1] == target[n-1]) step = min(step, tmp);

	if(step == INF) cout << "impossible" << endl;
	else cout << step << endl;
}