#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
using namespace std;

#define N 15

int main () {
	char english[N], foreign[N];
	map<string, bool> appear;  // 记录单词是否出现过
	map<string, string> dict;  // 字典映射

	while(1) {  // 输入字典
		char t = getchar();
		if(t == '\n')
			break;
		english[0] = t;
		int i = 1;
		while(1) {
			char ch = getchar();
			if(ch == ' ') {
				english[i] = '\0';
				break;
			}
			english[i++] = ch;
		}
		cin >> foreign;
		getchar();
		appear[foreign] = true;
		dict[foreign] = english;
	}
	char word[N];
	while(cin >> word) {
		if(appear[word])
			cout << dict[word] << endl;
		else
			cout << "eh" << endl;
	}
}