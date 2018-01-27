#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main () {
	double money;
	double sum = 0.0;
	for(int i = 0; i < 12; i++) {
		cin >> money;
		sum += money;
	}
	sum /= 12.0;
	cout << "$" << fixed << setprecision(2) << sum << endl;
	// system("pause");
}