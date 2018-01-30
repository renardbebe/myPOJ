#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

/*
(1):当盘子数为1的时候，只有一种放法就是把所有苹果放到一个盘子里。
(2):当苹果数为1的时候，也只有一种放法，注意题目中说明，盘子之间并无顺序,所以不管这个苹果放在哪个盘子里，结果都算一个。
(3):当m<n时，因为此时最多只能放到m个盘子中去（一个里放一个），实际上就相当于把m个苹果放到m个盘子里一样，也就是f(m,m);
(4):当m==n时,此时分两种情况讨论，一种是一个盘子里放一个，只是一种，第二种是，至少有一个盘子里不放苹果这就相当于是f(m,m-1);
(5):当m>n时，也分两种情况讨论，一种是至少有一个盘子里不放苹果，这样子就相当于f(m,n-1),第二种是，先取出n个苹果一个盘子里放一个，再将剩下的m-n个苹果放到n个盘子里去，即f(m-n,n);
*/

int f(int m, int n) {
	if(m == 1 || n == 1) return 1;
	if(m < n) return f(m, m);
	if(m == n) {
		return 1 + f(m, n-1);
	}
	if(m > n) {
		return f(m-n, n) + f(m, n-1);
	}
}

int main () {
	int T;
	cin >> T;
	while(T--) {
		int m, n;
		cin >> m >> n;
		cout << f(m, n) << endl;
	}
}