#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int n, d;

struct Seg
{
	double a;  // 线段的起终点
	double b;
}seg[1001];

bool cmp(const Seg& a, const Seg& b) {  // 按线段的右端点排序
	if(a.b != b.b) return (a.b < b.b);
	else return (a.a > b.a);
}

bool cover(double a, double b, int i) {
	if(b > d || b < (-d)) return false;  // 雷达不能覆盖
	double dis = sqrt(d*d - b*b);
	seg[i].a = a - dis;
	seg[i].b = a + dis;
	return true;
}

int main () {
	int kase = 1;
	while(cin >> n >> d && n && d) {
		bool flag = false;
		int cnt = 0;
		memset(seg, 0, sizeof(seg));
		for(int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			if(!cover(x,y,i)) {
				flag = true;
			}
		}
		if(d < 0 || flag) {  // 不能到达
			cout << "Case " << kase++ << ": " << -1 << endl;
			continue;
		}
		sort(seg, seg+n, cmp);
		double edge = -999999;
		for(int i = 0; i < n; i++) {
			if(edge < seg[i].a) {  // 需要多放一个雷达
				edge = seg[i].b;
				cnt++;
			}
		}
		cout << "Case " << kase++ << ": " << cnt << endl;
	}
}