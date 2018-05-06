#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

#define N 30
string a[N];

bool check(string s) {
	int len = s.length();
	for(int i = 0; i < len; i++) {
		int j = len-1-i;
		if(i > j) break;
		if(s[i] != s[j]) return false;
	}
	return true;
}

bool checksub(string s) {
	int h = 0;
	for(int i = 0; i < s.length(); i++) {
		h += s[i] - '0';
	}
	string tmp = "";
	while(h) {
		tmp += (h%10 + '0');
		h /= 10;
	}
	if(check(tmp)) return true;
	else return false;
}

int main () {
	int T, cnt = 0;
	cin >> T;
	for(int i = 0; i < T; i++) {
		cin >> a[i];
		if(check(a[i]) && checksub(a[i])) cnt++;
	}
	cout << cnt << endl;
}