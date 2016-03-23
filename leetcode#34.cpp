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
	vector<int> searchRange(vector<int>& nums, int target) {
		int l = -1, r = nums.size() - 1;
		while (l < r - 1){
			int mid = (l + r) / 2;
			if (nums[mid] < target) l = mid;
			else r = mid;
		}
		vector<int> ans;
		if (nums[r] != target){
			ans = { -1, -1 };
			return ans;
		}
		ans.push_back(r);
		l = 0; r = nums.size();
		while (l < r - 1){
			int mid = (l + r) / 2;
			if (nums[mid] > target) r = mid;
			else l = mid;
		}
		ans.push_back(l);
		return ans;
	}
};
int main()
{
	Solution sol;
	system("pause");
}