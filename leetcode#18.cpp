#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#define maxn 222222
#define Mint 111111111
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ans;
		int r = 0;
		vector<int> temp;
		if (nums.size()>0)
			sort(nums.begin(), nums.end());
		int a1, a2;
		for (int j = 0; j < (int)nums.size() - 3; j++){
			if (j>0 && nums[j] == nums[j - 1])
				continue;
			for (int i = j + 1; i < (int)nums.size() - 2; i++){
				if (i>j+1 && nums[i] == nums[i - 1])
					continue;
				a1 = i + 1;
				a2 = nums.size() - 1;
				while (a1 < a2){
					if (nums[a1] + nums[a2] == target-nums[i]-nums[j]){
						temp.clear();
						temp.push_back(nums[j]);
						temp.push_back(nums[i]);
						temp.push_back(nums[a1]);
						temp.push_back(nums[a2]);
						if (r == 0 || !(temp[0] == ans[r - 1][0] && temp[1] == ans[r - 1][1] && temp[2] == ans[r - 1][2] && temp[3] == ans[r-1][3])){
							ans.push_back(temp);
							r++;
						}
					}
					if (nums[a1] + nums[a2] < target-nums[i]-nums[j])
						a1++;
					else
						a2--;
				}
			}
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	vector<int> a = { 0, 0, 0, 0 };
	sol.fourSum(a, 0);
	system("pause");
}