#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

#define N 110

struct Point
{
	int x;
	int y;
	double dis;
	Point(){}
	Point(int x1, int y1, double d) {
		x = x1;
		y = y1;
		dis = d;
	}
	bool operator < (const Point &b) const {
		if(dis < b.dis) return true;
		else if( (dis-b.dis) < 1e-6 ) {
			if(x < b.x) return true;
			else if(x == b.x)
				return y < b.y;
			else return false;
		}
		else return false;
	}
};

Point p[N];

double cal(const Point a, const Point b) {
	return sqrt( (double)(1.0*(a.x-b.x)*(a.x-b.x)) + (double)(1.0*(a.y-b.y)*(a.y-b.y)) );
}

int main () {
	int x1, y1;
	cin >> x1 >> y1;
	Point a(x1, y1, 0.0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
		p[i].dis = cal(p[i], a);
	}
	sort(p, p+n);
	for(int i = 0; i < n; i++) {
		cout << "(" << p[i].x << "," << p[i].y << ")";
		if(i != n-1) cout << ",";
	}
	cout << endl;
	while(1);
}