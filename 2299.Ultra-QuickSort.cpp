#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

// merge-sort
#define N 500005
int a[N], b[N];
long long ans;

void merge(int start, int mid, int end) {
	int i = start, j = mid+1, k = start;
	while(i <= mid && j <= end) {
		if(a[i] <= a[j])
			b[k++] = a[i++];
		else {
			ans += j-k;
			b[k++] = a[j++];
		}
	}
	while(i <= mid) b[k++] = a[i++];
	while(j <= end) b[k++] = a[j++];
	for(int i = start; i <= end; i++) a[i] = b[i];
}

void Sort(int left, int right) {
	if(left < right) {
		int mid = (left+right)/2;
		Sort(left, mid);
		Sort(mid+1, right);
		merge(left, mid, right);
	}
}

int main () {
	int n;
	while(cin >> n && n) {
		ans = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		Sort(0, n-1);
		cout << ans << endl;
	}
}