#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int ans = nums[0];
		vector<int> f;
		f.push_back(nums[0]);
		for (int i = 1; i < nums.size(); i++)
		{
			f.push_back(f[i - 1] + nums[i]);
			if (nums[i] > f[i])
				f[i] = nums[i];
			if (f[i] > ans)
				ans = f[i];
		}
		return ans;
	}
};

int main()
{
	Solution a;
	
	system("pause");
}
