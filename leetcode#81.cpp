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
	int search(vector<int>& nums, int target) {
		while (nums.size()>1 && nums[nums.size() - 1] == nums[0])
			nums.resize(nums.size() - 1);
		int l = 0, r = nums.size();
		int k = nums[0];
		while (l + 1 < r){
			int mid = (l + r) / 2;
			if (nums[mid] >= k) l = mid;
			else r = mid;
		}
		int zpos = l + 1;
		l = 0; r = zpos;
		while (l + 1 < r){
			int mid = (l + r) / 2;
			if (nums[mid] > target) r = mid;
			else l = mid;
		}
		if (l<nums.size() && nums[l] == target) return true;
		l = zpos; r = nums.size();
		while (l + 1 < r){
			int mid = (l + r) / 2;
			if (nums[mid] > target) r = mid;
			else l = mid;
		}
		if (l<nums.size() && nums[l] == target) return true;
		return false;
	}
};

int main(){
	Solution sol; 
	vector<int> a = {1 };
	cout << sol.search(a, 0);
	system("pause");
}