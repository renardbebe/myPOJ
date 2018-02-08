#include <iostream>
#include <iomanip>
using namespace std;

int main () {
	double sum = 2.5;
	cout << "n e" << endl
		 << "- -----------" << endl;
	for(int i = 0; i <= 9; i++) {
		if(!i) cout << "0 1" << endl;
		else if(i == 1) cout << "1 2" << endl;
		else if(i == 2) cout << "2 2.5" << endl;
		else {
			double tmp = 1.0;
			for(int j = 1; j <= i; j++) {
				tmp *= j;
			}
			sum += 1.0 / tmp;
			cout << i << " " << fixed << setprecision(9) << sum << endl;
		}
	}
}