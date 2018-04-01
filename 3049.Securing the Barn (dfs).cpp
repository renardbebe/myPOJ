#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

int l, c;
char seq[100];
char res[20];
map<char, int> vowel;

bool check() {  // 判断是否合法
	int cnt = 0;
	for(int i = 0; i < l; i++) {
		if(vowel[res[i]])
			cnt++;
	}
	return (((l-cnt) >= 2) && (cnt >= 1));
}

void dfs(int base, int len) {
	if(len == l) {
		if(check()) {
			for(int i = 0; i < l; i++) cout << res[i];
			cout << endl;
		}
		return;
	}
	for(int i = base; i < c; i++) {
		res[len] = seq[i];
		dfs(i+1, len+1);
	}
}

int main () {
	vowel['a'] = vowel['e'] = vowel['i'] = vowel['o'] = vowel['u'] = 1;
	cin >> l >> c;
	for(int i = 0; i < c; i++) {
		cin >> seq[i];
	}
	sort(seq, seq+c);
	dfs(0, 0);
}