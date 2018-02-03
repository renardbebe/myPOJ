#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

int main () {
	int n;
	while(cin >> n && n) {
		long long ans = 0;
		bool flag = false;
		int i, j, cnt = 1, day = 1;
		for(i = 1; i <= n; i+=j) {
			for(j = 1; j <= cnt; j++) {
				ans += cnt;
				day++;
				if(day > n) {
					flag = true;
					break;
				}
			}
			if(flag) break;
			j--;
			cnt++;
		}
		cout << n << " " << ans << endl;
	}
}