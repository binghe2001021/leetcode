#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#define maxn 1111
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m, n;
		m = matrix.size();
		n = matrix[0].size();
		int i = 0;
		int j = 0;
		while (i < m && matrix[i][0] <= target) i++;
		if (i == 0) return false;
		i--;
		while (j < n && matrix[i][j] <= target) j++;
		if (j == 0) return false;
		return matrix[i][j - 1] == target;
	}
};

int main(){
	Solution sol;
}