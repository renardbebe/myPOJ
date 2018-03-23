#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
using namespace std;

#define N 1505
typedef long long LL;

LL ugly[N];

/* 暴力解法
bool is_ugly (int num) {
	if(num <= 6) return true;

	while(num % 2 == 0) num /= 2;
	while(num % 3 == 0) num /= 3;
	while(num % 5 == 0) num /= 5;
	return (num == 1);
}

void init () {
	int i = 0;
	for(int num = 1; i < N; num++) {
		if(is_ugly(num))
			ugly[i++] = num;
	}
}*/

const int coeff[3] = {2, 3, 5};

/* 利用STL优先队列从小到大生成各个ugly number
   最小的丑数是1，而对于任意丑数x，2x，3x和5x也都是丑数 */

void init () {
	priority_queue<LL, vector<LL>, greater<LL> > pq;
	set<LL> s;
	pq.push(1);
	s.insert(1);
	for(int i = 1; i < N; i++) {
		LL x = pq.top();
		pq.pop();
		ugly[i-1] = x;

		for(int j = 0; j < 3; j++) {
			LL tmp = x * coeff[j];
			if(!s.count(tmp)) {  // 注意去重
				pq.push(tmp);
				s.insert(tmp);
			}
		}
	}
}

int main () {
	int n;
	init();
	while(cin >> n && n) {
		cout << ugly[n-1] << endl;
	}
}