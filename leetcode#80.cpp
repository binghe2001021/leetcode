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
	int removeDuplicates(vector<int>& nums) {
		int cnt = 0;
		for (int i = 0; i < nums.size(); i++)
			if (i < 2 || !(nums[i] == nums[i - 1] && nums[i] == nums[i - 2])){
				cnt++;
			}
			else{
				nums.erase(nums.begin() + i);
				i--;
			}
			return cnt;
	}
};

int main(){
	Solution sol; 
	vector<int> a = { 1, 1, 2, 2, 3 };
	cout << sol.removeDuplicates(a);
}