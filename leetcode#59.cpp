#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#define maxn 222222
#define Mint 111111111
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> ans;
		int i = 0, j = 0;
		int di = 0, dj = 1;
		bool hash[1111];
		int cnt = 0;
		memset(hash, 0, sizeof hash);
		ans.resize(n);
		for (int i = 0; i < n; i++)
			ans[i].resize(n);
		while (i >= 0 && i<n && j >= 0 && j<n && !hash[i*n + j]){
			hash[i*n + j] = true;
			ans[i][j] = ++cnt;
			if (j + dj >= n || (hash[(i + di)*n + j + dj] && dj == 1)){
				di = 1; dj = 0;
			}
			if (i + di >= n || (hash[(i + di)*n + j + dj] && di == 1)){
				di = 0; dj = -1;
			}
			if (j + dj < 0 || (hash[(i + di)*n + j + dj] && dj == -1)){
				dj = 0; di = -1;
			}
			if (i + di < 0 || (hash[(i + di)*n + j + dj] && di == -1)){
				di = 0; dj = 1;
			}
			i += di;
			j += dj;
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	system("pause");
}