#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

#define SIZE 205

char b[SIZE];
int a[SIZE];

int main () {
	for(int i = 0; i < SIZE; i++) {
		a[i] = 0;
	}
	while(1) {
		scanf("%s", b);
		if(strcmp(b, "0") == 0)
			break;
		// 反转
		int len = strlen(b);
		for(int i = 0; b[i] != '\0'; i++) {
			a[i] += (b[len-1-i] - '0');
		}
	}
	for(int i = 0; i < SIZE; i++) {
		if(a[i] > 9) {
			a[i+1] += a[i] / 10;
			a[i] %= 10;
		}
	}
	int j = 0;
	for(j = SIZE-1; a[j] == 0; j--);
	for(; j >= 0; j--)
		cout << a[j];
	cout << endl;
}