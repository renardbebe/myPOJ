#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main () {
	int n;
	cin >> n;
	while(n--) {
		string s;
		cin >> s;
		int len = s.length();
		int cnt = 1;
		char ch = '#';
		for(int i = 0; i < len; i++) {
			if(s[i] != ch) {
				if(ch != '#') {
					if(cnt > 1) cout << cnt;
					cout << ch;
				}
				ch = s[i];
				cnt = 1;
			}
			else {
				cnt++;
			}
		}
		if(cnt > 1) cout << cnt;
		cout << ch << endl;
	}
}