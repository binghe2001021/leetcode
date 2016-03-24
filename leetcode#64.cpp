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
	int minPathSum(vector<vector<int>>& grid) {
		int n = grid[0].size();
		int m = grid.size();
		int f[111][111];
		f[0][0] = grid[0][0];
		for (int i = 1; i < n; i++)
			f[0][i] = f[0][i - 1] + grid[0][i];
		for (int i = 1; i < m; i++)
			f[i][0] = f[i - 1][0] + grid[i][0];
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
		return f[m - 1][n - 1];
	}
};

int main()
{
	Solution sol;
	system("pause");
}