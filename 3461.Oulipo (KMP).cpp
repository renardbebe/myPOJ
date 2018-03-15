#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

/* 字符串匹配 KMP算法 */

const int maxn = 1000005;

int nextp[maxn];
char s1[maxn], s2[maxn];

void getnext(char *s) {
	int len = strlen(s);
	int j = 0, k = -1;
	nextp[0] = -1;
	while(j < len) {
		if(k == -1 || s[j] == s[k]) {
			nextp[++j] = ++k;
		}
		else k = nextp[k];
	}
}

int kmp(char *s1, char *s2) {
	int l1 = strlen(s1), l2 = strlen(s2);
	int i = 0, j = 0, sum = 0;
	getnext(s2);

	while(i < l1 && j < l2) {
		if(j == -1 || s1[i] == s2[j]) {
			i++;j++;
		}
		else j = nextp[j];
		if(j == l2) {
			sum++;
			j = nextp[j];
		}
	}
	return sum;
}

int main () {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", s1);
		scanf("%s", s2);
		printf("%d\n", kmp(s2, s1));
	}
}