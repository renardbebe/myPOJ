#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

#define N 15
int a[N], b[N];

int main () {
	int n;
	while(cin >> n && n != -1) {
		int total = 0;
		for(int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i];
			total += a[i] * (b[i]-b[i-1]);
		}
		cout << total << " miles" << endl;
	}
}