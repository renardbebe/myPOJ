#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int main () {
	int a, b;
	while(cin >> a >> b) {
		if(a > b) swap(a, b);
		double x = (1.0 + sqrt(5.0)) / 2.0;
		int tmp = floor((b-a)*x);  // 计算第b-a个奇异局势, 上取整
		if(a == tmp) cout << 0 << endl;
		else cout << 1 << endl;
	}
}