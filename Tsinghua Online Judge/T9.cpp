#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
using namespace std;

#define MAXN 100

struct String
{
	string str;
	int step;
	String(string s, int move) {
		str = s;
		step = move;
	}
};

int main () {
	int len, min_step = MAXN;
	cin >> len;
	string s;
	cin >> s;

	queue<String> q;
	map<string, int> visit;
	q.push(String(s, 0));
	visit[s] = 1;
	bool find = true;
	while(!q.empty()) {
		String head = q.front();
		q.pop();
		if(head.step > MAXN) {
			find = false;
			break;
		}
		if(head.str.find("2012") != string::npos) {
			min_step = head.step;
			break;
		}
		for(int i = 1; i < head.str.length(); i++) {
			// swap
			string tmp = head.str;
			char ch = tmp[i-1];
			tmp[i-1] = tmp[i];
			tmp[i] = ch;
			if(!visit[tmp]) {
				q.push(String(tmp, head.step+1));
				visit[tmp] = 1;
			}
		}
	}
	if(!find)
		cout << -1 << endl;
	else
		cout << min_step << endl;
	while(1);
}