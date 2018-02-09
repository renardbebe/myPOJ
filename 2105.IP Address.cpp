#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int covert(string str) {
	int num = 0;
	int len = str.length();
	for(int i = 0; i < len; i++) {
		int j = 7-i;
		num += (str[i] - '0') * (int)(pow(double(2), j));
	}
	return num;
}

int main () {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		string s, tmp = "";
		cin >> s;
		for(int j = 0; j < s.length(); j++) {
			tmp += s[j];
			if((j+1)%8 == 0) {
				int sum = covert(tmp);
				if(j == 7) cout << sum;
				else cout << "." << sum;
				tmp = "";
			}
		}
		cout << endl;
	}
}