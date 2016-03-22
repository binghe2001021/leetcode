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
	int threeSumClosest(vector<int>& nums, int target) {
		int ans;
		int Min = 111111111;
		if (nums.size()>0)
			sort(nums.begin(), nums.end());
		int a1, a2;
		for (int i = 0; i < (int)nums.size()-2; i++){
			if (i>0 && nums[i] == nums[i - 1])
				continue;
			a1 = i + 1;
			a2 = nums.size()-1;
			while (a1<a2){
				if (abs(nums[a1]+nums[a2]+nums[i]-target)<Min){
					Min = abs(nums[a1] + nums[a2] + nums[i] - target);
					ans = nums[a1] + nums[a2] + nums[i];
				}
				if (nums[a1] + nums[a2] < target-nums[i])
					a1++;
				else
					a2--;
			}
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	vector<int> a;
	a.resize(5);
	a = { 1,1,-1,-1,3};
	sol.threeSumClosest(a,3);
	system("pause");
}