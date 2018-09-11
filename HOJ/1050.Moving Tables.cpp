#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 410
int cnt[N];

int main () {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < n; i++) {
			int s, e;
			cin >> s >> e;
			if(s > e) swap(s, e);

			if(s%2 == 0) s -= 1;     // 考虑实际情况，出发房间为偶数时-1
			if(e%2 == 1) e += 1;     // 目的地房间为奇数时+1

			for(int p = s; p <= e; p++) {
				cnt[p] += 10;
			}
		}
		int maxn = *max_element(cnt, cnt+400);
		cout << maxn << endl;
	}
}