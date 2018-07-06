#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

/*
        保证每5个月都亏损  x 为每5个月中的亏损月数量
        x=1:  ssssd,ssssd,ss    d>4s     赢利10个月    10s-2d
        x=2:  sssdd,sssdd,ss    2d>3s    赢利8个月     8s-4d
        x=3:  ssddd,ssddd,ss    3d>2s    赢利6个月     6s-6d
        x=4:  sdddd,sdddd,sd    4d>s     赢利3个月     3s-9d
        x=5:  ddddd,ddddd,dd    4d<s     无赢利
 */

int main () {
	int s, d;
	while(cin >> s >> d) {
		int left = 0;
		if(d > 4*s) left = 10*s - 2*d;
		else if(2*d > 3*s) left = 8*s - 4*d;
		else if(3*d > 2*s) left = 6*s - 6*d;
		else if(4*d > s) left = 3*s - 9*d;
		else left = -1;

		if(left < 0) cout << "Deficit" << endl;
		else cout << left << endl;
	}
}