#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int map[36] = {1, 1, 2, 1, 2, 3, 1, 2, 3, 4,
			   1, 2, 3, 4, 5, 1, 2, 3, 4, 5,
			   6, 1, 2, 3, 4, 5, 6, 7, 1, 2,
			   3, 4, 5, 6, 7, 8};

int main () {
	__int64 k, n;
	cin >> k;
	while(k--) {
		cin >> n;
		while(n > 36) n /= 9;
		cout << map[n-1] << endl;
	}
}