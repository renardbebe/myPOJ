#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

/*
 pos1 = (x+m*step)%L
 pos2 = (y+n*step)%L
 pos1 = pos2, 即(m-n)*step+k*L = y-x
 */

// 拓展欧几里得
long long extgcd(long long a, long long b, long long &x, long long &y) {
    long long d, t;
    if (b == 0) {
    	x = 1; y = 0;
    	return a;
    }
    d = extgcd(b, a % b, x, y);
    t = x - a / b * y; x = y; y = t;
    return d;
}

int main() {
    long long x, y, m, n, L, X, Y, d, r;
    while (cin >> x >> y >> m >> n >> L) {
        d = extgcd(n - m, L, X, Y);
        r = L / d;
        if ((x - y) % d)
        	cout << "Impossible" << endl;
        else
        	cout << ((x - y) / d * X % r + r) % r << endl;
    }
}