#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

#define N 110
int n, m, s;
double v;
double money[N], tmp[N], pay[N][N], rate[N][N];

bool floyd() {  // 判断是否有正环
	for(int i = 1; i <= n; i++)
		tmp[i] = money[i];
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				money[j] = max(money[j], (money[i] - pay[i][j]) * rate[i][j] );  // 将i货币换成j货币
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		if(tmp[i] < money[i])  // increase money
			return true;
	}
	return false;
}

int main () {
	cin >> n >> m >> s >> v;
	for(int i = 0; i < m; i++) {
		int a, b;
		double c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		rate[a][b] = c; pay[a][b] = d;
		rate[b][a] = e; pay[b][a] = f;
	}
	money[s] = v;
	bool flag = false;
	for(int t = 1; t <= 5; t++) {
		/*
			若存在正环，那么循环无数次之后一定是可以赚回本钱的。

			不可以只进行一次循环就判断本金是否增加，
			因为万一转为本金的佣金很高，
			但是存在一个一次增加一点点的正环的话就需要循环很多次才可以高于本金。
		 */
		flag = floyd();
	}

	if(flag) cout << "YES\n";
	else cout << "NO\n";
}