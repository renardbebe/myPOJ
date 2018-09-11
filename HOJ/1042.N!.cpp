#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

#define MAX 10005
map<int, string> multi;
// 高精度乘法

inline string toString(int x) {
	string ret = "";
	while(x) {
		ret += (x%10) + '0';
		x /= 10;
	}
	string result = "";
	for(int i = ret.length()-1; i >= 0; i--)
		result += ret[i];
	return result;
}

inline string big_add(string str1, string str2) {
	string tmp = "", result = "";
	int len1 = str1.length(), len2 = str2.length();
	int cnt = abs(len2 - len1);
	for(int i = 0; i < cnt; i++)
		tmp += "0";
	if(len1 < len2) {
		tmp += str1;
		str1 = tmp;
	}
	else {
		tmp += str2;
		str2 = tmp;
	}
	int len = str1.length();
	string ret = "";
	int carry = 0;
	for(int i = len-1; i >= 0; i--) {
		int h = str1[i] - '0' + str2[i] - '0' + carry;
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
	return result;
}

inline void init() {  // TLE !!
	multi[0] = "1";  multi[1] = "1";  multi[2] = "2";
	for(int num = 3; num < MAX; num++) {
		string s1 = toString(num), s2 = multi[num-1];
		// s1*s2
		int len1 = s1.length(), len2 = s2.length();
		int cnt = 0;
		vector<string> vec;
		// multiply
		for(int i = len1-1; i >= 0; i--) {
			int carry = 0;
			string tmp = "";
			// shift
			for(int k = 0; k < cnt; k++)
				tmp += "0";
			for(int j = len2-1; j >= 0; j--) {
				int h = (s1[i] - '0') * (s2[j] - '0') + carry;
				carry = h/10;
				tmp += (h%10) + '0';
			}
			if(carry) {
				tmp += (carry%10) + '0';
			}

			cnt++;
			string str = "";
			for(int k = tmp.length()-1; k >= 0; k--)
				str += tmp[k];
			vec.push_back(str);
		}
		// add
		string ret = "";
		for(std::vector<string>::iterator it = vec.begin(); it != vec.end(); it++) {
			ret = big_add(ret, *it);
		}
		multi[num] = ret;
		// cout << num << " " << ret << endl;
	}
}

int main(){
	int n;
	while(scanf("%d", &n) != EOF) {
		memset(num, 0, sizeof(num));
		num[0] = 1, num[1] = 1;    // num[0] 记录位数，num[i] 记录每一位的数字
		for(int i = 2; i <= n; i++) {
			int len = num[0];
			// 每一位 *i
			for(int j = 1; j <= len; j++) num[j] *= i;
			// 进位
			for(int j = 1; j <= num[0]; j++) {
				if( num[j] > 9 )
					num[j+1] += num[j]/10, num[j] %= 10;
				if( num[num[0]+1] )
					num[0] += 1;
			}
		}
		for(int i = num[0]; i >= 1; i--) putchar(num[i]+'0');
		puts("");
	}
}
