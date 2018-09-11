#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

string result, s;
int target;
int visit[30];

inline void dfs (int len, string substring) {
	// cout << len << " * " << substring << endl;
	if(len == 5) {
		double sum = 0.0;
		for(int i = 0; i < (int)substring.length(); i++) {
			sum += pow(double(substring[i] - 'A' + 1), double(i+1)) * pow(-1.0, i);
		}

		if(abs(sum - target) < 1e-7) {
			if(result < substring) result = substring;
		}
		return;
	}

	for(int i = 0; i < (int)s.length(); i++) {
		if(!visit[s[i] - 'A']) {
			visit[s[i] - 'A'] = 1;
			dfs(len+1, substring + s[i]);
			visit[s[i] - 'A'] = 0;
		}
	}
}

int main () {
	while(cin >> target >> s) {
		if(target == 0 && s == "END") break;

		result = "";
		memset(visit, 0, sizeof(visit));
		dfs(0, "");
		if(result != "") cout << result << endl;
		else cout << "no solution" << endl;
	}
}