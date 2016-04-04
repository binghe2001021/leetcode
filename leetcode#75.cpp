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
	void sortColors(vector<int>& nums) {
		int i, j, k;
		i = j = k = -1;
		int l = nums.size();
		for (int r = 0; r < l; r++){
			if (nums[r] == 0){
				nums[++k] = 2;
				nums[++j] = 1;
				nums[++i] = 0;
			}
			else
				if (nums[r] == 1){
					nums[++k] = 2;
					nums[++j] = 1;
				}
				else
					if (nums[r] == 2){
						nums[++k] = 2;
					}
		}
	}
};

int main(){
	Solution sol;
}