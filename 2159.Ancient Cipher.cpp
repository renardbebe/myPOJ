#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

// WA: //重排和映射并不是固定,是自己定的

int main () {
	string password, ori;
	cin >> password >> ori;
	int cnt1[26] = {0,}, cnt2[26] = {0,};
	int len = password.length();
	for(int i = 0; i < len; i++) {
		cnt1[password[i] - 'A']++;
		cnt2[ori[i] - 'A']++;
	}
	sort(cnt1, cnt1+26);
	sort(cnt2, cnt2+26);
	for(int i = 0; i < 26; i++) {
		if(cnt1[i] != cnt2[i]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	while(1);
}