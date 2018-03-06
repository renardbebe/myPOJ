#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main () {
	string s1, s2;
	while(cin >> s1 >> s2) {
		int len1 = s1.length(), len2 = s2.length();
		bool flag = false;
		for(int i = 0, j = 0; i < len1 && j < len2; ) {
			if(s1[i] == s2[j]) {
				i++;
				j++;
				if(i == len1) {
					flag = true;
					break;
				}
			}
			else j++;
		}
		if(flag) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}