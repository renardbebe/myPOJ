#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

#define N 110

struct String
{
	string str;
	int num;  // 记录逆序对个数
};
String a[N];

bool cmp(const String &a, const String &b) {
	return a.num < b.num;
}

int merge(string s, int begin, int mid, int end) {
	int cnt = 0;
	string result;
	int i = begin;
	int j = mid+1;
	while(i <= mid && j <= end) {
		if(s[i] <= s[j]) {
			result += s[i++];
		}
		else {
			cnt += mid-i+1;
			result += s[j++];
		}
	}
	while(j <= end)
		result += s[j++];
	while(i <= mid)
		result += s[i++];
	return cnt;
}

int mergeSort(string s, int begin, int end) {
	int cnt = 0;
	if(begin < end) {
		int mid = (begin + end) / 2;
		mergeSort(s, begin, mid);
		mergeSort(s, mid+1, end);
		cnt = merge(s, begin, mid, end);
	}
	return cnt;
}

int main () {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i].str;
		a[i].num = mergeSort(a[i].str, 0, a[i].str.length()-1);
	}
	sort(a, a+n, cmp);
	for(int i = 0; i < n; i++) {
		cout << a[i].str << endl;
	}
}