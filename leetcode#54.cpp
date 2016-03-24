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
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ans;
		if (matrix.empty())
			return ans;
		int i = 0, j = 0;
		int di = 0, dj = 1;
		int n = matrix.size();
		int m = matrix[0].size();
		bool hash[1111];
		memset(hash, 0, sizeof hash);
		while (i>=0 && i<n && j>=0 && j<m && !hash[i*m+j]){
			hash[i*m + j] = true;
			ans.push_back(matrix[i][j]);
			if (j + dj >= m || (hash[(i + di)*m + j + dj] && dj == 1)){
				di = 1; dj = 0;
			}
			if (i + di >= n || (hash[(i + di)*m + j + dj] && di == 1)){
				di = 0; dj = -1;
			}
			if (j + dj < 0 || (hash[(i + di)*m + j + dj] && dj == -1)){
				dj = 0; di = -1;
			}
			if (i + di < 0 || (hash[(i + di)*m + j + dj] && di == -1)){
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
	vector<vector<int>> a = { {2,3} };
	vector<int> res;
	res=sol.spiralOrder(a);
	for (int i = 0; i < res.size(); i++){
		printf("%d ",res[i]);
	}
	system("pause");
}