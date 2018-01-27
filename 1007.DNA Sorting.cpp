#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

#define N 105

struct Str
{
	string str;
	int cnt;  // 逆序个数
};

bool cmp(const Str &a, const Str& b) {
	return a.cnt < b.cnt;
}

int main () {
	int n, m;
	cin >> n >> m;
	Str s[N];
	for(int i = 0; i < m; i++) {
		cin >> s[i].str;
	}
	for(int i = 0; i < m; i++) {
		int A = 0, C = 0, G = 0, T = 0, total = 0;
		for(int j = n-1; j >= 0; j--) {  // 统计逆序个数
			switch(s[i].str[j]) {
				case 'A' : A++;break;
				case 'C' : C++;total+=A;break;
				case 'G' : G++;total+=(A+C);break;
				case 'T' : T++;total+=(A+C+G);break;
				default : break;
			}
		}
		s[i].cnt = total;
	}
	sort(s, s+m, cmp);
	for(int i = 0; i < m; i++) {
		cout << s[i].str << endl;
	}
	system("pause");
}