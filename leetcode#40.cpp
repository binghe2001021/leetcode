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
	vector<vector<int>> ans;
	vector<int> now;
	int n;
	void dfs(vector<int>& candidates, int depth, int target){
		if (depth >= n){
			if (target == 0)
				ans.push_back(now);
			return;
		}
		if (target >= candidates[depth]){
			now.push_back(candidates[depth]);
			dfs(candidates, depth + 1, target - candidates[depth]);
			now.resize(now.size() - 1);
		}
		dfs(candidates, depth + 1, target);
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		n = candidates.size();
		dfs(candidates, 0, target);
		for (int i = 1; i < ans.size(); i++)
			for (int k = 0; k < i; k++){
				if (ans[i].size() != ans[k].size())
					continue;
				int p = false;
				for (int j = 0; j < ans[i].size() && j < ans[k].size(); j++){
					if (ans[i][j] != ans[k][j]){
						p = true;
						break;
					}
				}
				if (!p) {
					ans.erase(ans.begin() + i);
					i--;
					break;
				}
			}
		return ans;
	}
};

int main()
{
	Solution sol;
	system("pause");
}