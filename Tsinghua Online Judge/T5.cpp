#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;

map<char, int> cost;
map<char, int> pos;

void init() {
	cost['a'] = 1; cost['b'] = 2; cost['c'] = 3;
	cost['d'] = 1; cost['e'] = 2; cost['f'] = 3;
	cost['g'] = 1; cost['h'] = 2; cost['i'] = 3;
	cost['j'] = 1; cost['k'] = 2; cost['l'] = 3;
	cost['m'] = 1; cost['n'] = 2; cost['o'] = 3;
	cost['p'] = 1; cost['q'] = 2; cost['r'] = 3; cost['s'] = 4;
	cost['t'] = 1; cost['u'] = 2; cost['v'] = 3;
	cost['w'] = 1; cost['x'] = 2; cost['y'] = 3; cost['z'] = 4;

	pos['a'] = pos['b'] = pos['c'] = 2;
	pos['d'] = pos['e'] = pos['f'] = 3;
	pos['g'] = pos['h'] = pos['i'] = 4;
	pos['j'] = pos['k'] = pos['l'] = 5;
	pos['m'] = pos['n'] = pos['o'] = 6;
	pos['p'] = pos['q'] = pos['r'] = pos['s'] = 7;
	pos['t'] = pos['u'] = pos['v'] = 8;
	pos['w'] = pos['x'] = pos['y'] = pos['z'] = 9;
}

int main () {
	string s;
	init();
	while(cin >> s) {
		int len = s.length(), t = 0;
		for (int i = 0; i < len; i++) {
			t += cost[s[i]];
			if(!i) continue;
			if(pos[s[i]] == pos[s[i-1]]) {
				t += 2;
			}
		}
		cout << t << endl;
	}
}