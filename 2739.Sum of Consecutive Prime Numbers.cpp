#include <iostream>
using namespace std;

#define maxp 2000
#define N 10005

int prime[maxp], total;

bool isprime(int k) {
	for(int i = 0; i < total; i++) {
		if(k%prime[i] == 0)
			return false;
	}
	return true;
}

int main () {
	for(int i = 2; i <= N; i++) {
		if(isprime(i))
			prime[total++] = i;
	}
	prime[total] = N+1;
	int m;
	while(cin >> m && m) {
		int ans = 0;
		for(int i = 0; prime[i] <= m; i++) {
			int sum = 0;
			for(int j = i; j < total && sum < m; j++)
				sum += prime[j];
			if(sum == m)
				ans++;
		}
		cout << ans << endl;
	}
}