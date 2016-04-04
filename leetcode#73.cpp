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
	void setZeroes(vector<vector<int>>& matrix) {
		int m, n;
		m = matrix.size();
		n = matrix[0].size();
		vector<int> row;
		vector<int> col;
		for (int i = 0; i < m;i++)
			for (int j = 0; j < n; j++){
				if (matrix[i][j] == 0){
					row.push_back(i);
					col.push_back(j);
				}
			}
		int lw = row.size(), ll = col.size();
		for (int i = 0; i < lw; i++)
			for (int j = 0; j < n; j++)
				matrix[row[i]][j] = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < ll; j++)
				matrix[i][col[j]] = 0;
	}
};

int main(){
	Solution sol;
}