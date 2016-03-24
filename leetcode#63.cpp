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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int f[111][111];
		int n = obstacleGrid[0].size();
		int m = obstacleGrid.size();
		f[0][0] = 1 - obstacleGrid[0][0];
		for (int i = 1; i < n; i++){
			if (obstacleGrid[0][i] == 0)
				f[0][i] = f[0][i - 1];
			else
				f[0][i] = 0;
		}
		for (int i = 1; i < m; i++)
			if (obstacleGrid[i][0] == 0)
				f[i][0] = f[i-1][0];
			else
				f[i][0] = 0;
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++){
				if (obstacleGrid[i][j] == 1){
					f[i][j] = 0;
					continue;
				}
				f[i][j] = f[i - 1][j] + f[i][j - 1];
			}
		return f[m - 1][n - 1];
	}
};

int main()
{
	Solution sol;
	system("pause");
}