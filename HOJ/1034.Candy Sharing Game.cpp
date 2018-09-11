#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

#define N 210
int n, apple[N], convert[N];

inline bool check() {
	for(int i = 1; i < n; i++)
		if(apple[i] != apple[0]) return false;
	return true;
}

int main () {
	while(cin >> n && n) {
		for(int i = 0; i < n; i++) {
			cin >> apple[i];
		}
		int times = 0;
		bool flag = check();
		while(!flag) {
			for(int i = 0; i < n; i++) {
				convert[i] = apple[i] / 2;
			}
			for(int i = 0; i < n; i++) {
				apple[i] /= 2;
				if(i) apple[i] += convert[i-1];
				else apple[i] += convert[n-1];
				if(apple[i] % 2) apple[i] += 1;
			}
			times++;
			flag = check();
		}
		cout << times << " " << apple[0] << endl;
	}
}