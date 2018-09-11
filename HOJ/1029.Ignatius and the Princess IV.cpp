#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define N 1000005
int a[N];

int main () {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a+n);
        printf("%d\n", a[(n-1)/2]);
    }
}