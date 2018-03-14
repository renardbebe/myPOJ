#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main () {
	string s;
	while(getline(cin, s) && s != "#") {
		int len = s.length();
		int sum = 0;
		for(int i = 0; i < len; i++) {
			if(s[i] == ' ') continue;
			sum += (i+1) * (s[i] - 'A' + 1);
		}
		cout << sum << endl;
	}
}