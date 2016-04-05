#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#define maxn 1111
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	int len;
	vector<vector<int>> ans;
	vector<int> now;
	bool hash[111111];
	void dfs(vector<int>& nums, int depth, int n){
		if (depth >= n){
			ans.push_back(now);
			return;
		}
		dfs(nums, depth + 1, n);
		if (depth > 0 && nums[depth] == nums[depth - 1]){
			if (!hash[depth - 1])
				return;
		}
		hash[depth] = 1;
		now.push_back(nums[depth]);
		dfs(nums, depth + 1, n);
		hash[depth] = 0;
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		len = nums.size();
		memset(hash, 0, sizeof(hash));
		dfs(nums, 0, len);
		return ans;
	}
};
int main(){
	Solution sol; 
	system("pause");
}