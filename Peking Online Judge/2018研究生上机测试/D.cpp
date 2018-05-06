#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

#define N 10010

struct Schedule
{
	int start;
	int end;
}a[N];

bool cmp(const Schedule &a, const Schedule &b) {
	return a.end < b.end;  // 按结束时间排序
}

/* 日程安排 贪心 */

int main () {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i].start >>a[i].end;
	}
	sort(a, a+n, cmp);
	int cnt = 0;
	int last_time = -1;
	for(int i = 0; i < n; i++) {
		if(a[i].start >= last_time) {
			last_time = a[i].end;
			cnt++;
		}
	}
	cout << cnt << endl;
}