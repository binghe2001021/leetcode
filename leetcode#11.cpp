#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int l = 0;
		int r = height.size()-1;
		int ans = 0;
		while (l < r){
			ans = max(ans, min(height[l], height[r])*(r - l));
			if (height[l] < height[r])
				l++;
			else
				r--;
		}
		return ans;
	}
};

int main()
{
	string t = "acbbca";
	vector<int> a = { 1, 1 };
	Solution s;
	printf("%d\n", s.maxArea(a));
	system("pause");
}