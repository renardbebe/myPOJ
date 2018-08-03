#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define N 10010

struct Point
{
	int x, y;
	Point() {}
	Point(int _x, int _y) {
		x = _x, y = _y;
	}
};

Point a[N];

inline bool cmp1 (const Point p1, const Point p2) {  // sort by y-cor
	return p1.y < p2.y;
}

inline bool cmp2 (const Point p1, const Point p2) {  // sort by x-cor
	return p1.x < p2.x;
}

int main () {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	sort(a, a+n, cmp1);
	int average_y = a[n/2].y;

	sort(a, a+n, cmp2);
	for(int i = 0; i < n; i++) {
		a[i].x -= i;
	}
	sort(a, a+n, cmp2);
	int average_x = a[n/2].x;

	int move = 0;
	for(int i = 0; i < n; i++) {
		move += int(abs(a[i].y - average_y));
		move += int(abs(a[i].x - average_x));
	}
	cout << move << endl;
	system("pause");
}