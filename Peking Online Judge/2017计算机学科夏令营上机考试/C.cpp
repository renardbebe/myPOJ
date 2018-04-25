#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

#define N 110
int n, m;
int land[N][N];

int main () {
	cin >> n >> m;
	int len = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++)
			cin >> land[i][j];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++)
			if(land[i][j]) {
				len += 4;
				len -= (land[i-1][j] + land[i+1][j] + land[i][j-1] + land[i][j+1]);
			}
	}
	cout << len << endl;
	while(1);
}