#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

#define N 110

int main () {
	string str;
	getline(cin, str);
	vector<string> s;
	string tmp = "";
	for(int i = 0; i <= str.length(); i++) {
		if(str[i] == ' ' || i == str.length()) {
			s.push_back(tmp);
			tmp = "";
		}
		else {
			tmp += str[i];
		}
	}
	int size = s.size();
	for(int i = size-1; i >= 0; i--) {
		cout << s[i];
		if(i) cout << " ";
	}
	cout << endl;
}