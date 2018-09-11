#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int main () {
	int T;
	cin >> T;
	for(int kase = 1; kase <= T; kase++) {
		string s1, s2, result = "", tmp = "";
		cin >> s1 >> s2;
		int len1 = s1.length(), len2 = s2.length();
		cout << "Case " << kase << ":" << endl;
		cout << s1 << " + " << s2 << " = ";

		// padding zero to same length
		int cnt = abs(len2 - len1);
		for(int i = 0; i < cnt; i++)
			tmp += "0";
		if(len1 < len2) {
			tmp += s1;
			s1 = tmp;
		}
		else {
			tmp += s2;
			s2 = tmp;
		}
		int len = s1.length();

		string ret = "";
		int carry = 0;
		for(int i = len-1; i >= 0; i--) {
			int h = s1[i] - '0' + s2[i] - '0' + carry;
			carry = h/10;
			ret += (h%10) + '0';
		}
		if(carry) {
			ret += (carry%10) + '0';
		}

		int i = ret.length()-1;
		// remove leading zero
		while(ret[i] == '0') i--;
		for(i; i >= 0; i--) {
			result += ret[i];
		}
		cout << result << endl;
		if(kase != T) cout << endl;
	}
}