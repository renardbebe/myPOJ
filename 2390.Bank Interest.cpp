#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int main () {
	double r, m, y;
	cin >> r >> m >> y;
	double p = 0.0;
	for(int i = 1; i <= y; i++) {
		m += p;
		p = 0.01*r*m;
	}
	cout << int(m+p) << endl;
}