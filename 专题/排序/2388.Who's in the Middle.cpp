#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

#define N 10010
int n, a[N];

int main () {
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);
	cout << a[n/2] << endl;
}