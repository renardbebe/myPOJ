#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

int main () {
	int k;
	int Joseph[14] = {0, };  // 打表，保存各个k值对应的m值
	while(cin >> k && k) {
		if(Joseph[k]) {
			cout << Joseph[k] << endl;
			continue;
		}
		int n = 2*k;  // 总人数
		int m = k+1;  // 最小的报数
		int ans[30] = {0, };  // 记录每轮被杀掉的人的编号(编号从0开始)
		for(int i = 1; i <= k; i++) {  // 轮数
			ans[i] = (ans[i-1]+m-1) % (n-i+1);  // 递推公式
			if(ans[i] < k) {  // 杀了好人
				i = 0;
				m++;  // 枚举
			}
		}
		Joseph[k] = m;
		cout << m << endl;
	}
}