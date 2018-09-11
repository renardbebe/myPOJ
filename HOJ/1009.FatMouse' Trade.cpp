#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;

#define MAX 1010

struct CatFood
{
	int javabean;
	int food;
	double bean_per_food;
	CatFood() {}
}a[MAX];

inline bool cmp (const CatFood &a, const CatFood &b) {  // 按照性价比排序
	return (a.bean_per_food > b.bean_per_food);
}

int main () {
	int M, N;
	while(cin >> M >> N && M != -1 && N != -1) {
		for(int i = 0; i < N; i++) {
			cin >> a[i].javabean >> a[i].food;
			a[i].bean_per_food = (double) 1.0 * a[i].javabean / a[i].food;
		}
		sort(a, a+N, cmp);

		double earn = 0.0;
		for(int i = 0; i < N && M; i++) {
			if(M >= a[i].food) {
				earn += a[i].javabean;
				M -= a[i].food;
			}
			else {
				earn += M * a[i].bean_per_food;
				M = 0;
			}
		}
		cout << fixed << setprecision(3) << earn << endl;
	}
}