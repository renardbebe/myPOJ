#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

/* 矩阵快速幂 */

#define INF 0x3f3f3f3f
#define M 10000

struct Mat {
    long long m[2][2];
    Mat() {
        memset(m, 0, sizeof(m));
    }
};

Mat multi (Mat a, Mat b) {
    Mat c;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                c.m[i][j] += (a.m[i][k] * b.m[k][j]) % M;
            }
        }
    }
    return c;
}

Mat zxc (Mat a, long long b) {
    Mat c;
    c.m[0][0] = c.m[1][1] = 1;
    while (b) {
        if (b & 1)
            c = multi(c, a);
        a = multi(a, a);
        b >>= 1;
    }
    return c;
}

int main () {
    long long n;
    while (cin >> n && n != -1) {
        Mat one;
        if (n == 0) {
            cout << 0 << endl;
            continue;
        }
        else if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        one.m[0][0] = one.m[1][0] = one.m[0][1] = 1;
        one = zxc(one, n-1);
        cout << one.m[0][0] % M << endl;;
    }
}