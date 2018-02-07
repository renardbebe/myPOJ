#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

#define N 15
char s1[N], s2[N], info[N];
int flag[N];  // 记录可疑值

int main () {
	int n;
	scanf("%d", &n);
	while(n--) {
		memset(flag, 0, sizeof(flag));
		int maxn = 10;
		for(int time = 1; time <= 3; time++) {  // 称重次数
			scanf("%s%s%s", &s1, &s2, &info);
			int len = strlen(s1);
			if(strcmp(info, "even") == 0) {
				for(int i = 0; i < len; i++) {
					flag[s1[i] - 'A'] = maxn;  // 说明两边都为真，将标记数组置为10
					flag[s2[i] - 'A'] = maxn;
				}
			}
			else if(strcmp(info, "up") == 0) {
				for(int i = 0; i < len; i++) {
					if(flag[s1[i] - 'A'] != maxn) flag[s1[i] - 'A']++;  // 左加右减
					if(flag[s2[i] - 'A'] != maxn) flag[s2[i] - 'A']--;
				}
			}
			else {
				for(int i = 0; i < len; i++) {
					if(flag[s1[i] - 'A'] != maxn) flag[s1[i] - 'A']--;
					if(flag[s2[i] - 'A'] != maxn) flag[s2[i] - 'A']++;
				}
			}
		}
		int pos, num = -1;
		for(int i = 0; i < 12; i++) {
			if(flag[i] == maxn) continue;
			if(abs(flag[i]) > num) {
				num = abs(flag[i]);
				pos = i;
			}
		}
		if(flag[pos] > 0)
			printf("%c is the counterfeit coin and it is heavy.\n",'A'+pos);
		else
			printf("%c is the counterfeit coin and it is light.\n",'A'+pos);
	}
}