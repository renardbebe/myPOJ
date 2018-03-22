#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;

#define N 500005
int a[N];
map<int, int> visit;

void init() {
	a[0] = 0;
	visit[0] = 1;
	for(int i = 1; i < N; i++) {
		if((a[i-1] - i) > 0 && !visit[a[i-1] - i]) {
			a[i] = a[i-1] - i;
			visit[a[i]] = 1;
		}
		else {
			a[i] = a[i-1] + i;
			visit[a[i]] = 1;
		}
	}
}

int main () {
	int n;
	init();
	while(cin >> n) {
		if(n == -1) break;
		cout << a[n] << endl;
	}
}