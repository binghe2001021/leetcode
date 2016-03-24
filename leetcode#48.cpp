#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#define maxn 222222
#define Mint 111111111
using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		vector<vector<int>> temp;
		temp.resize(n);
		for (int i = 0; i < n; i++)
			temp[i].resize(n);
		for (int j = n - 1; j >= 0; j--)
			for (int i = 0; i < n; i++)
				temp[i][j] = matrix[n - j - 1][i];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				matrix[i][j] = temp[i][j];
	}
};

int main()
{
	Solution sol;
	vector<vector<int>> a = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	sol.rotate(a);
	system("pause");
}