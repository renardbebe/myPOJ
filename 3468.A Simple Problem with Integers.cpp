#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

#define N 100000
#define SIZE 4*N

int num[SIZE];

struct node {
    int l, r;
    long long nsum;
    long long add;  // 统计增量，用于区间更新
}seg[SIZE];

void Build(int i, int l, int r) {
    seg[i].l = l;
    seg[i].r = r;
    seg[i].add = 0;
    if(l == r) {
        seg[i].nsum = num[l];
        return ;
    }
    int mid = l+((r-l)>>1);
    Build(i<<1, l, mid);
    Build(i<<1|1, mid+1, r);
    seg[i].nsum = seg[i<<1].nsum + seg[i<<1|1].nsum;
}

void Add(int i, int l, int r, long long c) {  // 对区间内的所有数+c
    if(seg[i].l == l && seg[i].r == r) {
        seg[i].add += c;
        return ;
    }
    seg[i].nsum += c*(r-l+1);
    int mid = (seg[i].l+seg[i].r)>>1;
    if(r <= mid)
    	Add(i<<1, l, r, c);
    else if(l > mid)
    	Add(i<<1|1, l, r, c);
    else {
        Add(i<<1, l, mid, c);
        Add(i<<1|1, mid+1, r, c);
    }
}

long long Query(int i,int a,int b) {  // 查询a-b的总和
    if(seg[i].l == a && seg[i].r == b)
	    return seg[i].nsum + (b-a+1)*seg[i].add;
    seg[i].nsum += (seg[i].r-seg[i].l+1)*seg[i].add;
    int mid = (seg[i].l+seg[i].r)>>1;
    Add(i<<1, seg[i].l, mid, seg[i].add);
    Add(i<<1|1, mid+1, seg[i].r, seg[i].add);
    seg[i].add = 0;
    if(b <= mid)
    	return Query(i<<1, a, b);
    else if(a > mid)
    	return Query(i<<1|1, a, b);
    else
    	return Query(i<<1, a, mid) + Query(i<<1|1, mid+1, b);
}

int main() {
    int n, m, i;
    int a, b, c;
    char s[10];
    while(~scanf("%d%d", &n, &m)) {
        for(i = 1; i <= n; i++)
	        scanf("%d", &num[i]);
        Build(1, 1, n);  // 构建线段树
        for(i = 0; i < m; i++) {
            scanf("%s", s);
            if(s[0] == 'C') {
                scanf("%d%d%d", &a, &b, &c);
                Add(1, a, b, c);
            }
            else {
                scanf("%d%d", &a, &b);
                cout << Query(1, a, b) << endl;
            }
        }
    }
}