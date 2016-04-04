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
	vector<vector<int>> ans;
	int n;
	vector<int> now;
	bool hash[111111];
	void dfs(vector<int> nums, int depth){
		if (depth >= n){
			ans.push_back(now);
			return;
		}
		dfs(nums, depth + 1);
		if (depth>0 && nums[depth - 1] == nums[depth]){
			if (!hash[depth - 1])
				return;
		}
		now.push_back(nums[depth]);
		hash[depth] = true;
		dfs(nums, depth + 1);
		hash[depth] = false;
		now.resize(now.size() - 1);
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		n = nums.size();
		sort(nums.begin(), nums.end());
		now.resize(0);
		dfs(nums, 0);
		return ans;
	}
};

int main(){
	Solution sol;
	vector<int> a = { 1, 2, 3 };
	sol.subsets(a);
}