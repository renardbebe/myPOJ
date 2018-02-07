#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
using namespace std;

#define N 20
int a[N];

int main () {
	int x;
	while(1) {
		cin >> x;
		if(x == -1) break;
		map<int, int> appear;
		int num = 0;
		a[num++] = x;
		appear[x] = 1;
		while(cin >> x && x) {
			a[num++] = x;
			appear[x] = 1;
		}
		int cnt = 0;
		for(int i = 0; i < num; i++) {
			if(appear[2*a[i]])
				cnt++;
		}
		cout << cnt << endl;
	}
}