#include <cstdio>

int judge(int n,int m) {
	int cnt=0;
	for(int i=1;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			if((i*i+j*j+m) % (i*j) == 0)
			   cnt++;
		}
	}
	return cnt;
}

int main () {
	int i,N,n,m;
	scanf("%d", &N);
	getchar();
	getchar();
	for(i=0;i<N;i++) {
		int kase=1;
		while (scanf("%d%d", &n, &m)==2 && !(n==0&&m==0)) {
			int cnt = judge(n,m);
			printf("Case %d: %d\n", kase++, cnt);
		}
		if(i<N-1)  printf("\n");
	}
}