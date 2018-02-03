#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
using namespace std;

int main () {
	string command;
	stack<string> forward_;
	stack<string> backward_;
	string cur = "http://www.acm.org/";
	backward_.push(cur);
	while(cin >> command && command != "QUIT") {
		if(command == "VISIT") {
			string url;
			cin >> url;
			backward_.push(url);
			cur = url;
			cout << cur << endl;
			while(!forward_.empty())
				forward_.pop();
		}
		else if(command == "FORWARD") {
			if(!forward_.empty()) {
				cur = forward_.top();
				backward_.push(cur);
				cout << cur << endl;
				forward_.pop();
			}
			else cout << "Ignored" << endl;
		}
		else if(command == "BACK") {
			if(backward_.size() > 1) {  // 要先pop一个到forward里，然后才是当前页面
				forward_.push(cur);
				backward_.pop();
				cur = backward_.top();
				cout << cur << endl;
			}
			else cout << "Ignored" << endl;
		}
	}
}