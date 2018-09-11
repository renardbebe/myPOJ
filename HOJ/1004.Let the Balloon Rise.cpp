#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

map<string, int> cnt;

int main () {
	int n;
	while(cin >> n && n) {
		string color, ans;
		cnt.clear();
		int maxn = 0;
		for(int i = 0; i < n; i++) {
			cin >> color;
			cnt[color]++;
			if(cnt[color] > maxn) {
				maxn = cnt[color];
				ans = color;
			}
		}
		cout << ans << endl;
	}
}