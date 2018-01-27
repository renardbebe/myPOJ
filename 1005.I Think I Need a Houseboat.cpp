#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

const double pi = 3.1415926535;

int main () {
	int n;
	cin >> n;
	double x, y;
	for(int kase = 1; kase <= n; kase++) {
		cin >> x >> y;
		double squre_dis = x*x + y*y;
		double area = 0.5*pi*squre_dis;
		int year = (int) ceil(area / 50);  // 向上取整
		cout << "Property " << kase << ": This property will begin eroding in year " << year << ".\n";
	}
	cout << "END OF OUTPUT.\n";
}