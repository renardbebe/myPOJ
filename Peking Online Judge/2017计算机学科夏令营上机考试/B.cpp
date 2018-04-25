#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

int main () {
	string s;
	cin >> s;
	int len = s.length(), cnt = 0;
	bool conti = true;
	char ch = '#';
	for(int i = 0; i < len; i++) s[i] = tolower(s[i]);
	for(int i = 0; i < len; i++) {
		if(i && s[i] != s[i-1])
			conti = false;
		if(conti) {
			cnt++;
			if(ch == '#') cout << "(";
			ch = s[i];
		}
		else {
			cout << ch << "," << cnt << ")";
			cnt = 1;
			conti = true;
			ch = '#';
		}
	}
	cout << ch << "," << cnt << ")" << endl;
}