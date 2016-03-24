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
	bool hash[maxn];
	int n;
	vector<vector<int>> ans;
	vector<int> now;
	void dfs(vector<int>& nums, int depth){
		if (depth >= n){
			/*int r = ans.size() - 1;
			int p;
			if (ans.size() > 0){
				for (int j = r; j >= 0;j--){
					p = false;
					for (int i = 0; i < ans[r].size(); i++)
						if (ans[j][i] != now[i]){
							p = true;
							break;
						}
					if (!p) return;
				}
			}*/
			ans.push_back(now);
			return;
		}
		for (int i = 0; i < n; i++)
			if (!hash[i] && (i==0 || nums[i]!=nums[i-1] || hash[i-1]==true)){
				hash[i] = true;
				now.push_back(nums[i]);
				dfs(nums, depth + 1);
				hash[i] = false;
				now.resize(now.size() - 1);
			}
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		n = nums.size();
		for (int i = 0; i < n; i++){
			hash[i] = false;
		}
		sort(nums.begin(), nums.end());
		dfs(nums,0);
		return ans;
	}
};

int main()
{
	Solution sol;
	vector<int> a = { 1, 1,2 };
	vector<vector<int>> s;
	s = sol.permute(a);
	for (int i = 0; i < s.size(); i++){
		for (int j = 0; j < s[i].size()-1; j++)
			printf("%d ", s[i][j]);
		printf("%d\n", s[i][s[i].size() - 1]);
	}
	system("pause");
}