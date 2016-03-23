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
	void nextPermutation(vector<int>& nums) {
		int pos = -1;
		int pi;
		for (int i = nums.size() - 2; i >= 0; i--){
			if (nums[i] < nums[i + 1]){
				pi = i;
				for (int j = i + 1; j < nums.size(); j++)
					if (nums[j]>nums[i])
						pos = j;
				break;
			}
		}
		int temp;
		if (pos != -1){
			temp = nums[pi];
			nums[pi] = nums[pos];
			nums[pos] = temp;
			sort(nums.begin()+pi+1,nums.end());
		}
		else{
			int l = 0, r = nums.size()-1;
			while (l < r){
				temp = nums[l];
				nums[l] = nums[r];
				nums[r] = temp;
				l++;
				r--;
			}
		}
	}
};

int main()
{
	Solution sol;
	system("pause");
}