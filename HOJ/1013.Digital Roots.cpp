#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

int main () {
	string s;
	vector<int> digit;
	while(cin >> s && s != "0") {  // 输入数字可能很长，不能用 n 存
		int root = 0, n = 0;
		for(int i = 0; i < s.length(); i++)
			n += s[i] - '0';
		while(root > 9 || root == 0) {
			digit.clear();
			if(root > 9) {
				n = root;
				root = 0;
			}

			while(n) {
				int h = n%10;
				n /= 10;
				digit.push_back(h);
			}
			for(vector<int>::iterator it = digit.begin(); it != digit.end(); it++) {
				root += *it;
			}
		}
		cout << root << endl;
	}
}