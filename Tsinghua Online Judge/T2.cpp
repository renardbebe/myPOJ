#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main () {
	int n;
	while(cin >> n) {
		int num;
		for(int i = 0; i < n; i++) {
			cin >> num;
			int cnt = 0;
			for(int j = 1; j <= sqrt(num); j++) {
				if(num % j == 0) {
					if(j*j == num) cnt++;
					else cnt += 2;
				}
			}
			cout << cnt << endl;
		}
	}
}