#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

/* 推导一下求VR的公式：
   V2 = iR = CR d/dt (VS*cos(wt)-VR*cos(wt+q)) = VRcos(wt+q)
      = CR w (sin(wt+q)-sin(wt))
      = VRcos(wt+q)
   然后分别令 t=0 和 wt+q=0 得到 CRw tan b = 1 和 VR = CRw VS sin b
   最后利用三角函数中的万能公式，求得：VR = CRw VS / sqrt (1+(CRw)^2))
 */

int main () {
	int n;
	double vs, r, c, w, vr;
	cin >> vs >> r >> c >> n;
	for(int i = 0; i < n; i++) {
		cin >> w;
		vr = c * r * w * vs / sqrt(1+(c*r*w*c*r*w));
		printf("%.3lf\n", vr);
	}
}