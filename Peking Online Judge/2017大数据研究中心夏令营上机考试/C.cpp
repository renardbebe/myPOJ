#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

#define N 110
int n, m;
int table[N][N];
int after[N][N];

void update() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int cnt = table[i-1][j-1] + table[i-1][j] + table[i-1][j+1] +
					  table[i][j-1] + table[i][j+1] +
					  table[i+1][j-1] + table[i+1][j] + table[i+1][j+1];
			if(table[i][j] == 1) {
				if(cnt == 2 || cnt == 3) after[i][j] = 1;
				else after[i][j] = 0;
			}
			else {
				if(cnt == 3) after[i][j] = 1;
			}
		}
	}
}

int main () {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> table[i][j];
		}
	}
	update();
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(j > 1) cout << " ";
			cout << after[i][j];
		}
		cout << endl;
	}
	while(1);
}