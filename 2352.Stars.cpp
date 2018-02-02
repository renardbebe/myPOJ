#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

/* 树状数组 */

#define N 15005
#define MAX 32005
int c[MAX];
int level[N];

inline int lowbit(int x) {  // lowbit(x)是x的二进制表达式中最低位的1所对应的值
	return x&(-x);
}

inline int add(int x) {  // 对前x进行求和
	int res = 0;
	while(x > 0) {
		res += c[x];
		x -= lowbit(x);
	}
	return res;
}

void update(int x) {  // 给下标为x的加上1,这样的话下次询问前面的就能够累加上去了
	while(x <= MAX) {
		c[x]++;
		x += lowbit(x);
	}
}

int main () {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		level[add(x+1)]++;  // y递增，故只需要考虑x即可
		update(x+1);
	}
	for(int i = 0; i < n; i++) {
		printf("%d\n", level[i]);
	}
	system("pause");
}