#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

int main () {
	double n, p;
	while(cin >> n >> p) {
		double k = pow(p, 1/n);
		cout << k << endl;
	}
}