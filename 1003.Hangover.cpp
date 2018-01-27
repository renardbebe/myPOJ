#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

int main () {
	double a;
	while(cin >> a && a != 0) {
		int ans = 0;
		double sum = 0.0;
		int i = 2;
		while(1) {
			sum += 1.0/i;
			ans++;
			i++;
			if(sum > a) break;
		}
		cout << ans << " card(s)\n";
	}
}