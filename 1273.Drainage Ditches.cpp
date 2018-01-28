#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

#define  N 205
#define INF 111111111
using namespace std;

int flow[N][N], n, m, pre[N], capacity[N][N];

int Augmenting_Path(int src, int des, int num) {  // bfs寻找增广链,如果找，返回这条增广链的容量，否则返回-1
    int i, ret = INF;
    memset(pre, -1, sizeof(pre));
    queue<int> q;
    q.push(src);
    pre[src] = 0;
    while(!q.empty()) {
        int tmp = q.front();
        q.pop();
        for (i = 1; i <= num; i++) {
            if (pre[i] == -1 && flow[tmp][i] < capacity[tmp][i]){
                q.push(i);
                pre[i] = tmp;
                ret = min(ret, capacity[tmp][i]-flow[tmp][i]);
                if (i == des)
                	return ret;
            }
        }
    }
    return -1;
}

int Edmonds_Karp(int src, int des, int num) {  // 标号法寻找最大流量 src:原点   des:终点  num:结点数
    int i, ret = 0;
    while(1) {
        int Min = Augmenting_Path(src, des, num);
        if (Min == -1) {
            return ret;
        }
        i = des;
        while(i != src) {
            flow[pre[i]][i] += Min;
            flow[i][pre[i]] -= Min;
            i = pre[i];
        }
        ret += Min;
    }
}

int main() {
    int i, a, b, v;
    while(~scanf("%d%d", &m, &n)) {
        memset(capacity, 0, sizeof(capacity));
        memset(flow, 0, sizeof(flow));
        for (i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &v);
            capacity[a][b] += v;
        }
        printf("%d\n", Edmonds_Karp(1, n, n));
    }
}