#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

string ConvertToString(int i){
	if (i == 0) return "0";
	vector<int> temp;
	string ans;
	for (; i > 0; i /= 10){
		temp.push_back(i % 10);
	}
	for (int j = temp.size() - 1; j >= 0; j--){
		ans.push_back(temp[j] + 48);
	}
	return ans;
}

bool cmp(const int& a, const int& b){
	if (a == b) return false;
	string s1 = ConvertToString(a);
	string s2 = ConvertToString(b);
	return s1.append(s2) > s2.append(s1);
}

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		if (nums.empty()) return "";
		string ans = "";
		sort(nums.begin(), nums.end(), cmp);
		bool p = true;
		for (int i = 0; i < nums.size() - 1; i++)
			if (nums[i] != 0 || p == false){
				p = false;
				ans.append(ConvertToString(nums[i]));
			}
		ans.append(ConvertToString(nums[nums.size() - 1]));
		return ans;
	}
};

int main()
{
	Solution sol;
	
	system("pause");
}
