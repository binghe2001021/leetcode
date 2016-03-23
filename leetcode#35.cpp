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
	int searchInsert(vector<int>& nums, int target) {
		int l = 0, r = nums.size();
		while (l + 1 < r){
			int mid = (l + r) / 2;
			if (nums[mid] > target) r = mid;
			else l = mid;
		}
		return l+(nums[l]!=target && !(l==0 && nums[l]>target));
	}
};
int main()
{
	Solution sol;
	system("pause");
}