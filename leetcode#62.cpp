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
	int uniquePaths(int m, int n) {
		int f[111][111];
		for (int i = 0; i < n; i++)
			f[0][i] = 1;
		for (int i = 0; i < m; i++)
			f[i][0] = 1;
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++){
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