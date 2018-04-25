#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

#define N 110
#define MAXN 10001

vector<int> height;
int result1[N], result2[N];

int main () {
	int K;
	cin >> K;
	while(K--) {
		int n;
		cin >> n;
		height.clear();
		for(int i = 0; i < n; i++) {
			int h;
			cin >> h;
			height.push_back(h);
		}

		for(int i = 0; i < n; i++) {  // result[i]对应子序列[0~i]的最长上升子序列长度
			result1[i] = 1;
			result2[i] = 1;
		}
		int maxLen1 = 1, maxLen2 = 1;

		// 正向
		for(int i = 1; i < n; i++) {
			// update
			for(int j = 0; j < i; j++) {
				if(height[i] > height[j]) {
					result1[i] = max(result1[i], result1[j] + 1);
					maxLen1 = max(maxLen1, result1[i]);
				}
			}
		}
		reverse(height.begin(), height.end());
		// 反向
		for(int i = 1; i < n; i++) {
			// update
			for(int j = 0; j < i; j++) {
				if(height[i] > height[j]) {
					result2[i] = max(result2[i], result2[j] + 1);
					maxLen2 = max(maxLen2, result2[i]);
				}
			}
		}
		cout << max(maxLen1, maxLen2) << endl;
	}
}