#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#define maxn 222222
#define Mint 111111111
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		bool f[111111];
		int n = nums.size();
		f[n] = true;
		for (int i = n - 1; i >= 1; i--){
			if (i + nums[i - 1] >= n){
				f[i] = true;
				continue;
			}
			f[i] = false;
			for (int j = 0; j < nums[i - 1] && i + j + 1 <= n;){
				f[i] |= f[i + j + 1];
				if (f[i]) break;
				else j += nums[i + j]+1;
			}
		}
		return f[1];
	}
};

int main()
{
	Solution sol;
	vector<int> a = { 2, 1, 0, 1 };
	if (sol.canJump(a)) cout << 111 << endl;
	system("pause");
}