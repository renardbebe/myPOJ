#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

int T, start, destination, cnt;

void dfs(int cur) {
	if(cur >= destination) {
		if(cur == destination)
			cnt++;
		return;
	}
	dfs(cur+1);
	dfs(cur+2);
}

int main () {
	cin >> T;
	while(T--) {
		cin >> start >> destination;
		cnt = 0;
		dfs(start);
		cout << cnt << endl;
	}
}