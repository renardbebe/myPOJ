#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#define N 21
long long cal[N];

void init() {
	cal[1] = 1;
	cal[2] = 2;
	for(int i = 3; i < N; i++) {
		cal[i] = i * cal[i-1];
	}
}

int main () {
	int n;
	init();
	cin >> n;
	cout << cal[n] << endl;
}