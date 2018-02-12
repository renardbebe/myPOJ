#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

#define N 10
int a[N];

int main () {
	int t;
	cin >> t;
	while(t--) {
		for(int i = 0; i < 4; i++)
			cin >> a[i];
		if((a[1]-a[0]) == (a[2]-a[1]))
			a[4] = a[3] + (a[2]-a[1]);
		else if(a[0] && a[1] && (a[1]/a[0]) == (a[2]/a[1]))
			a[4] = a[3] * (a[2]/a[1]);
		for(int i = 0; i < 5; i++) {
			if(!i) cout << a[i];
			else cout << " " << a[i];
		}
		cout << endl;
	}
}