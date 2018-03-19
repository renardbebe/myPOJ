#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int main () {
	string s1, s2;
	cin >> s1 >> s2;
	int len1 = s1.length(), len2 = s2.length();
	int ans = 0;
	for(int i = 0; i < len1; i++) {
		for(int j = 0; j < len2; j++)
			ans += (s1[i] - '0') * (s2[j] - '0');
	}
	cout << ans << endl;
}