#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
using namespace std;

/*
先不考虑小数，转换为大整数求幂 R^n
然后在结果中添加小数点
小数点位置为 小数位数*n
 */

// 实现大数乘法
string BigNumMulti(string str1, string str2) {
	int len1 = str1.length();
	int len2 = str2.length();
	vector<int> res(len1+len2, 0);
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	for(int i = 0; i < len1; i++) {
		for(int j = 0; j < len2; j++) {
			res[i+j] += (str1[i] - '0') * (str2[j] - '0');
		}
	}
	for(int k = 0; k < (len1+len2); k++) {
		if(res[k] >= 10) {
			res[k+1] += res[k] / 10;
			res[k] %= 10;
		}
	}
	string result = "";
	for(int i = 0; i < (len1+len2); i++) {
		result += (res[i] + '0');
	}
	reverse(result.begin(), result.end());
	return result;
}

int main () {
	string input;
	while(getline(cin, input)) {
		string r = "";
		int n = 0;
		int dotCount = 0;
		int index = input.find(".");
		if(index == string::npos) {
			r = input.substr(0,6);
			n = atoi(input.substr(7,2).c_str());
		}
		else {
			dotCount = 5 - index;
			r = input.substr(0, index) + input.substr(index+1, dotCount);
			n = atoi(input.substr(7,2).c_str());
		}
		if(atoi(r.c_str()) == 0) {
			cout << 0 << endl;
			continue;
		}

		string res = r;
		// 循环相乘
		for(int i = 1; i < n; i++) {
			res = BigNumMulti(res, r);
		}
		// 小数点处理
		int cnt = dotCount * n;
		if(cnt != 0) {
			res = res.substr(0, res.length() - cnt) + "." + res.substr(res.length() - cnt, cnt);
		}
		// 删去前导零
		int i;
		for(i = 0; i < res.length() && res[i] == '0'; i++);
		// 删除小数点后的0
		int j;
		for(j = res.length()-1; j >= 0 && res[j] == '0'; j--);
		if(res[j] == '.')
			j--;
		res = res.substr(i, j+1-i);
		cout << res << endl;
	}
}