#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

#define N 100010
int x, y;
int a[N];

bool isprime(int i) {
	for(int j = 2; j <= sqrt(i); j++) {
		if(i%j == 0) return false;
	}
	return true;
}

void init() {
	memset(a,0,sizeof(a));
	a[1] = 0;
	a[2] = 1;
	for(int i = 3; i < N; i++) {
		if(isprime(i))
			a[i] = 1;
	}
}

int main () {
	cin >> x >> y;
	if(x > y) swap(x, y);  // x y没有说明大小关系
	init();
	int cnt = 0;
	for(int i = x; i <= y; i++) {
		if(a[i]) cnt++;
	}
	cout << cnt << endl;
	while(1);
}