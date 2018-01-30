#include <iostream>
#include <cstdlib>
using namespace std;

int main () {
	int T;
	cin >> T;
	while(T--) {
		int x, y;
		cin >> x >> y;
		if(x >= y) cout << "MMM BRAINS" << endl;
		else cout << "NO BRAINS" << endl;
	}
}