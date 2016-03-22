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
	vector<string> ans;
	int st = 0;
	void dfs(int n, int depth, string now){
		//'('
		if (depth == n && st==0){
			ans.push_back(now);
			return;
		}
		if (depth < n){
			now.push_back('(');
			st++;
			dfs(n, depth + 1, now);
			now.erase(now.size() - 1);
			st--;
		}
		//')'
		if (st!=0){
			now.push_back(')');
			st--;
			dfs(n, depth, now);
			st++;
			now.erase(now.size() - 1);
		}
	}

	vector<string> generateParenthesis(int n) {
		dfs(n,0,"");
		return ans;
	}
};

int main()
{
	Solution sol;
	sol.generateParenthesis(3);
	system("pause");
}