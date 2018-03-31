#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

#define N 30
int n, h;
int f[N];          // 每个池塘的初始鱼量
int d[N];          // 每个池塘鱼的衰减数量
int t[N];          // 从i到i+1的距离时间
int left_fish[N];  // 每个池塘的剩余鱼量

/* 贪心+枚举 */

struct Lack
{
	int maxn;     // 最大钓鱼量
	int num[N];   // 在每个池塘所花的时间
}lake[N];

int getmax (int p[], int i, int j) {  // 找出剩余鱼量最多的池塘下标
	int pos = -1, m = -1;
	for(int k = i; k <= j; k++) {
		if(p[k] > m) {
			m = p[k];
			pos = k;
		}
	}
	return pos;
}

void init() {
	for(int i = 1; i <= n; i++) {
		lake[i].maxn = 0;
		for(int j = 1; j <= n; j++) {
			lake[i].num[j] = 0;
		}
	}
}

void go_fish() {
	init();
	for(int i = 1; i <= n; i++) {  // 枚举结束钓鱼时的湖序号
		int cost = 0, total = h*60;
		for(int j = 1; j <= i; j++) {
			left_fish[j] = f[j];
			if(j < i) {
				total -= t[j]*5;
			}
		}
		while(cost < total) {  // 还有时间剩余
			int k = getmax(left_fish, 1, i);
			lake[i].num[k] += 5;
			lake[i].maxn += left_fish[k];
			left_fish[k] = (left_fish[k] > d[k]) ? (left_fish[k] - d[k]) : 0;
			cost += 5;
		}
	}
	int l = -1, m = -1;  // 必须是 -1 !
	for(int i = 1; i <= n; i++) {  // 找到可以获得最多鱼的结束鱼塘下标
		if(lake[i].maxn > m) {
			m = lake[i].maxn;
			l = i;
		}
	}
	for(int i = 1; i <= n; i++) {
        if(i != n)
            printf("%d, ", lake[l].num[i]);
        else
            printf("%d\n", lake[l].num[i]);
    }
    printf("Number of fish expected: %d\n\n", lake[l].maxn);
}

int main () {
	while(cin >> n && n) {
		cin >> h;
		for(int i = 1; i <= n; i++) {
			cin >> f[i];
		}
		for(int i = 1; i <= n; i++) {
			cin >> d[i];
		}
		for(int i = 1; i < n; i++) {
			cin >> t[i];
		}
		go_fish();
	}
}