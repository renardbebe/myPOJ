#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

#define N 20005
int a[N];

int f(int i) {
	int sum = i;
	while(i) {
		sum += i%10;
		i /= 10;
	}
	return sum;
}

int main () {
	for(int i = 1; i <= 10000; i++) {
		a[f(i)] = 1;
	}
	for(int i = 1; i <= 10000; i++) {
		if(!a[i])
			printf("%d\n", i);
	}
}