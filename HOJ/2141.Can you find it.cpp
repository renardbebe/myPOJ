#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

const int MAX_N = 505;

int A[MAX_N];
int B[MAX_N];
int C[MAX_N];
set<int> D;
int L, M, N, S;

bool Find(int key) {
    for(int i = 0; i < M; i++) {
        if(D.find(key-C[i]) != D.end()) {  // set 二分查找
            return true;
        }
    }
    return false;
}

int main() {
    int T = 0;
    while(scanf("%d %d %d",&L, &N, &M) != EOF) {
 		D.clear();
        for(int i = 0; i < L; i++)
            scanf("%d", &A[i]);
        for(int i = 0; i < N; i++)
            scanf("%d", &B[i]);
        for(int i = 0; i < M; i++)
            scanf("%d", &C[i]);

        for(int i = 0; i < L; i++) {
            for(int j = 0; j < N; j++) {
                D.insert(A[i]+B[j]);  // 构造新数组
            }
        }

        scanf("%d", &S);
        printf("Case %d:\n", ++T);
        while(S--) {
            int x;
            scanf("%d", &x);

            if(Find(x)) printf("YES\n");
            else printf("NO\n");
        }
    }
}