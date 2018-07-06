#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define N 500010
long long n, a[N], b[N];
long long cnt;

/* 逆序对 */

void merge(int left, int mid, int right) {
	int i = left, j = mid+1, k = left;
	while(i <= mid && j <= right) {
		if(a[i] < a[j]) b[k++] = a[i++];
		else {
			b[k++] = a[j++];
			cnt += (j-k);
		}
	}
	while(i <= mid) b[k++] = a[i++];
	while(j <= right) b[k++] = a[j++];
	// memcpy(a, b, sizeof(b));
	for(int i = left; i <= right; i++)
		a[i] = b[i];
}

void mergeSort(int left, int right) {
	if(left < right) {
		int mid = (left + right) / 2;
		mergeSort(left, mid);
		mergeSort(mid+1, right);
		merge(left, mid, right);
	}
}

int main () {
	while(cin >> n && n) {
		memset(a, 0, sizeof(a));
		cnt = 0;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		mergeSort(0, n-1);
		cout << cnt << endl;
	}
}