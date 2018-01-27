#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

map<char, char> mymap;
map<string, int> myCount;

string deal (string str) {
	int len = str.length();
	string ans = "";
	for(int i = 0; i < len; i++) {
		if(str[i] == '-') continue;
		else if(str[i] >= '0' && str[i] <= '9') ans += str[i];
		else {
			ans += mymap[str[i]];
		}
	}
	return ans;
}

int main () {
	int N;
	cin >> N;
	mymap['A'] = mymap['B'] = mymap['C'] = '2';
	mymap['D'] = mymap['E'] = mymap['F'] = '3';
	mymap['G'] = mymap['H'] = mymap['I'] = '4';
	mymap['J'] = mymap['K'] = mymap['L'] = '5';
	mymap['M'] = mymap['N'] = mymap['O'] = '6';
	mymap['P'] = mymap['R'] = mymap['S'] = '7';
	mymap['T'] = mymap['U'] = mymap['V'] = '8';
	mymap['W'] = mymap['X'] = mymap['Y'] = '9';
	string str;
	while(N--) {
		cin >> str;
		string s = deal(str);
		myCount[s] += 1;
	}
	int ans = 0;
	for(map<string, int>::iterator i = myCount.begin(); i != myCount.end(); i++) {
		if(i->second > 1) {
			ans++;
			string s = i->first;
			for(int j = 0; j < int(s.length()); j++) {
				cout << s[j];
				if(j == 2) cout << "-";
			}
			cout << " " << i->second << endl;
		}
	}
	if(ans == 0) cout << "No duplicates." << endl;
	system("pause");
}