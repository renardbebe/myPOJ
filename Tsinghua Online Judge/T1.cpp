#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define N 1010

struct Person
{
	string name;
	int score;
	Person() {}
	bool operator < (const Person &b) {
		return score < b.score;
	}
};

Person p[N];

bool cmp1 (const Person &a, const Person &b) {
	return a.score > b.score;
}

bool cmp2 (const Person &a, const Person &b) {
	return a.score < b.score;
}

int main () {
	int n, method;
	while(cin >> n >> method) {
		for(int i = 0; i < n; i++) {
			cin >> p[i].name >> p[i].score;
		}
		if(method == 0) {
			stable_sort(p, p+n, cmp1);
		}
		else {
			stable_sort(p, p+n, cmp2);
		}
		for(int i = 0; i < n; i++) {
			cout << p[i].name << " " << p[i].score << endl;
		}
	}
}