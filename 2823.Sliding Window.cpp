#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN (int)(1e6+10)

int maxIndex[MAXN], minIndex[MAXN], num[MAXN];
int maxAns[MAXN], minAns[MAXN];

/* 单调队列 or 线段树 求区间最大最小值 */

int main () {
	int n, k;
	while(~scanf("%d%d",&n,&k)) {
		int maxhead = 0, maxtail = 0, minhead = 0, mintail = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d", &num[i]);

			/* 删除下标超过范围的 */
			if(maxhead < maxtail && maxIndex[maxhead] <= (i-k)) maxhead++;
			if(minhead < mintail && minIndex[minhead] <= (i-k)) minhead++;

			/* 删除队尾比当前数字小的 */
			while(maxhead < maxtail && num[maxIndex[maxtail-1]] < num[i])
				maxtail--;
			maxtail++;
			maxIndex[maxtail-1] = i;
			maxAns[i] = num[maxIndex[maxhead]];

			while(minhead < mintail && num[minIndex[mintail-1]] > num[i])
				mintail--;
			mintail++;
			minIndex[mintail-1] = i;
			minAns[i] = num[minIndex[minhead]];
		}

		for(int i = k-1; i < n; i++) cout << minAns[i] << ' ';
		cout << endl;
		for(int i = k-1; i < n; i++) cout << maxAns[i] << ' ';
		cout << endl;
	}
}