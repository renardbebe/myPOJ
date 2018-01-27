#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
    int p, e, i, d, kase = 1;
    while (scanf("%d%d%d%d", &p, &e, &i, &d), ~p) {
        int x = (5544 * p + 14421 * e + 1288 * i - d + 21252) % 21252;
        if (x == 0) x = 21252;
        printf("Case %d: the next triple peak occurs in %d days.\n", kase++, x);
    }
}