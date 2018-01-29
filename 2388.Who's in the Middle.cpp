#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

#define N 10005
int a[N];

int main () {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a,a+n);
	cout << a[(n/2)] << endl;
}