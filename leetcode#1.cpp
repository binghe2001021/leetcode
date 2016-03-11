#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int len = nums.size();
		vector <int> ans(0);
		if (len == 0)
			return ans;
		for (int i = 0; i < len-1; i++)
			for (int j = i+1; j < len;j++)
				if (nums[i] + nums[j] == target){
					ans.push_back(i);
					ans.push_back(j);
					return ans;
				}
	}
};

int main()
{
	vector <int> a = {2,3,9,4,5,6};
	Solution s;
	system("pause");
}