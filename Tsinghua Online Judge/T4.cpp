#include <iostream>
#include <string>
using namespace std;

int main () {
	string s;
	while(cin >> s) {
		int len = s.length();
		for(int i = len-1; i >= 0; i--)
			printf("%c", s[i]);
		printf("\n");
	}
}