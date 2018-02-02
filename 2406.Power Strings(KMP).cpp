#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

/* KMP 算法
   假设S的长度为len，则S存在循环子串，当且仅当，len可以被len - next[len]整除，最短循环子串为S[len - next[len]] */

#define N 1000005
char s[N];
int next_[N];

void get_next(char s[], int len) {
	int i = 0, j = -1;
	next_[0] = -1;
	while(i < len) {
		if(j == -1 || s[i] == s[j]) {
			i++, j++;
			next_[i] = j;
		}
		else j = next_[j];
	}
}

int main () {
	while(~scanf("%s", &s)) {
		if(s[0] == '.') break;
		int len = strlen(s);
		get_next(s, len);
		if(len%(len-next_[len]) == 0)
			printf("%d\n", len/(len-next_[len]));
		else
			printf("1\n");
	}
}