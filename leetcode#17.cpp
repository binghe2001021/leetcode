#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#define maxn 222222
#define Mint 111111111
using namespace std;

const string st[10] = { "", "" , "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
class Solution {
public:
	vector<string> ans;
	void dfs(string digits, int depth, string now){
		if (depth > (int)digits.size() - 1){
			ans.push_back(now);
			return;
		}
		int k = digits[depth] - 48;
		for (int i = 0; i < st[k].size(); i++){
			now.push_back(st[k][i]);
			dfs(digits, depth + 1, now);
			now.erase(now.size()-1, 1);
		}
	}
	vector<string> letterCombinations(string digits) {
		ans.resize(0);
		if (digits.size()>0)
			dfs(digits, 0, "");
		return ans;
	}
};

int main()
{
	Solution sol;
	vector<string> res = sol.letterCombinations("23");
	for (int i = 0; i < res.size();i++)
		cout << res[i] << endl;
	system("pause");
}