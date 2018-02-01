#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int CircleNum(int i) {
	int cnt = 1;
	while(i != 1) {
		if(i%2)
			i = 3*i+1;
		else
			i = i/2;
		cnt++;
	}
	return cnt;
}

int main () {
	int a, b;
	while(cin >> a >> b) {
		int start = min(a, b);
		int end = max(a, b);
		int maxn = -1;
		for(int i = start; i <= end; i++) {
			int num = CircleNum(i);
			maxn = max(maxn, num);
		}
		cout << a << " " << b << " " << maxn << endl;
	}
}