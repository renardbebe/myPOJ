#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#define N 10010

struct Product
{
	int value, date;  // 价值、截止日期
	Product() {}
	Product(int v, int d) {
		value = v, date = d;
	}
};
Product p[N];
int visit[N];

bool cmp (const Product &a, const Product &b) {
	if(a.value == b.value) a.date < b.date;
	else return a.value > b.value;
}

int main () {
	int n;
	while(cin >> n) {
		for(int i = 0; i < n; i++) {
			cin >> p[i].value >> p[i].date;
		}
		int profit = 0;  // 最大利润
		sort(p, p+n, cmp);
		memset(visit, 0, sizeof(visit));
		for(int i = 0; i < n; i++) {
			for(int j = p[i].date; j >= 1; j--) {  // 从截止日期往前找，尽量将前面的时间留出来
				if(!visit[j]) {
					visit[j] = 1;
					profit += p[i].value;
					break;
				}
			}
		}
		cout << profit << endl;
	}
}