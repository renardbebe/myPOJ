#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stack>
using namespace std;

inline bool isVar (char ch) {
	return ((ch == 'p') || (ch == 'q') || (ch == 'r') || (ch == 's') || (ch == 't'));
}

int main () {
	string str;
	while(cin >> str) {
		if(str == "0") return 0;

		int len = str.length();
		bool flag = false;
		stack<int> myStack;
		for(int p = 0; p <= 1 && !flag; p++) {
			for(int q = 0; q <= 1 && !flag; q++) {
				for(int r = 0; r <= 1 && !flag; r++) {
					for(int s = 0; s <= 1 && !flag; s++) {
						for(int t = 0; t <= 1 && !flag; t++) {  // 枚举所有变量状态
							while(!myStack.empty()) myStack.pop();
							for(int i = len-1; i >= 0; i--) {
								if(isVar(str[i])) {
									switch(str[i]) {
										case 'p' : myStack.push(p); break;
										case 'q' : myStack.push(q); break;
										case 'r' : myStack.push(r); break;
										case 's' : myStack.push(s); break;
										case 't' : myStack.push(t); break;
									}
								}
								else {
									if(!myStack.empty()) {
										switch(str[i]) {
											case 'K' : {
												int x = myStack.top();
												myStack.pop();
												int y = myStack.top();
												myStack.pop();
												myStack.push(x && y);
												break;
											}
											case 'A' : {
												int x = myStack.top();
												myStack.pop();
												int y = myStack.top();
												myStack.pop();
												myStack.push(x || y);
												break;
											}
											case 'N' : {
												int x = myStack.top();
												myStack.pop();
												myStack.push(!x);
												break;
											}
											case 'C' : {
												int x = myStack.top();
												myStack.pop();
												int y = myStack.top();
												myStack.pop();
												myStack.push((!x) || y);
												break;
											}
											case 'E' : {
												int x = myStack.top();
												myStack.pop();
												int y = myStack.top();
												myStack.pop();
												myStack.push(x == y);
												break;
											}
										}
									}
								}
							}
							int head = myStack.top();
							if(head == 0)
								flag = true;
						}
					}
				}
			}
		}
		if(flag) cout << "not" << endl;
		else cout << "tautology" << endl;
	}
}